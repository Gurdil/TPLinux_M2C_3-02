/*
 * map.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "map.h"
#include "puce.h"

DLmap::DLmap(int size):
				size(size),
				generator(std::chrono::system_clock::now().time_since_epoch().count())
{
	cases = new DLCase[size*size];

	std::uniform_int_distribution<int> distribution(0, size-1);

	int xDog = distribution(generator);
	int yDog = distribution(generator);
	dogAuraSize = 2;

	cases[this->convert(xDog, yDog)].setDog();
	cases[this->convert(xDog, yDog)].setPound(1);


	for (int i = ((xDog-dogAuraSize < 0) ? 0 : xDog-dogAuraSize); i < ((xDog+dogAuraSize >= size) ? size : xDog+dogAuraSize+1); ++i)
	{
		for (int j = ((yDog-dogAuraSize < 0) ? 0 : yDog-dogAuraSize); j < ((yDog+dogAuraSize >= size) ? size : yDog+dogAuraSize+1); ++j)
		{
			DLCase *box = &cases[this->convert(i, j)];
			if(!box->getDog())
			{
				int diffLine =std::abs(xDog-i);
				int diffCol =std::abs(yDog-j);
				box->setPound(( diffLine > diffCol)?diffLine+1 : diffCol+1);
			}
		}
	}
}

DLmap::~DLmap()
{
	delete [] cases;
}

int DLmap::convert(int i, int j)
{
	if(i<0 || i>(size-1) || j<0 || j>(size-1))
	{
		throw std::out_of_range("Out of range in map : "+std::to_string (i)+", "+std::to_string (j));
	}
	return i*size + j;
}

void DLmap::show()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			DLCase *box = &cases[this->convert(i, j)];
			if(box->getPuce() != NULL)
			{
				std::cout << 'F';
			}
			else
			{
				int pound = (int)box->getPound();
				if(pound>0)
				{
					std::cout << pound;
				}
				else
				{
					std::cout << "_";
				}
			}
		}
		std::cout <<std::endl;
	}
}

void DLmap::setPuce(DLpuce *puce)
{
	while(true)
	{
		std::uniform_int_distribution<int> distribution(0, size*size-1);
		int boxIndex = distribution(generator);
		if(cases[boxIndex].getDog())
		{
			continue;
		}
		if(cases[boxIndex].getPuce() != NULL)
		{
			continue;
		}
		cases[boxIndex].setPuce(puce);
		break;
	}
}

bool DLmap::setPuce(int line, int col, DLpuce *puce, int range)
{
	if(cases[this->convert(line, col)].getDog())
	{
		cases[range].setPuce(NULL);
		return true;
	}
	else if (cases[this->convert(line, col)].getPuce() != NULL)
	{
		return false;
	}
	else if(cases[range].getPound() != 0 && cases[this->convert(line, col)].getPound() == 0)
	{
		return false;
	}
	else if (cases[range].getPound() != 0 && cases[range].getPound() < cases[this->convert(line, col)].getPound())
	{
		return false;
	}
	else
	{
		cases[range].setPuce(NULL);
		cases[this->convert(line, col)].setPuce(puce);
		return false;
	}

}

bool DLmap::jumpPuce(int jumpX, int jumpY, DLpuce *puce)
{
	int range = 0;
	while(puce != cases[range].getPuce() && range != size*size)
	{
		range++;
	}

	if(range == size*size)
	{
		//throw std::out_of_range("Access to a flea not on map.");
		return true;
	}

	int lin = convertLin(range) + jumpY;
	int col = convertCol(range) + jumpX;

	if(lin<0 || lin>(size-1) || col<0 || col>(size-1))
	{
		return false;
	}

	return this->setPuce(lin, col,puce,range);

}

int DLmap::convertLin(int range)
{
	return (range - this->convertCol(range))/size;
}

int DLmap::convertCol(int range)
{
	return range%size;
}
