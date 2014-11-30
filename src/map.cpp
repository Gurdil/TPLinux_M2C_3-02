/*
 * map.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "map.h"

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

	this->show();

}

DLmap::~DLmap()
{
	delete [] cases;
}

int DLmap::convert(int i, int j)
{
	if(i<0 || i>(size-1) || j<0 || j>(size-1))
	{
		throw std::out_of_range("Out of range in map");
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

