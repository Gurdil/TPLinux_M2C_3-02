/*
 * DLControler.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: gurdil
 */

#include "DLControler.h"

DLControler::DLControler(int size) :
	DLthread(),
	size(size),
	map(size),
	listPuce(),
	listSavePuce(),
	listPuceDog()
{
	sem_init(&stop, 0, 0);
	data = new char[size*size];
	sem_init(&dataReaded, 0, 0);
	sem_init(&semPuceDog, 0, 1);
	sem_init(&gameEnd, 0, 0);

	nbPuce = (double)(size*size)/100*10;


	for (int i = 0; i < nbPuce; ++i)
	{
		DLpuce * puce = new DLpuce(this);
		listPuce.push_back(puce);
		listSavePuce.push_back(puce);
		map.setPuce(puce);
	}

	this->map.writeData(data);
	sem_init(&dataWrited, 0, 1);

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->start();
	}

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->go();
	}
}

int DLControler::getNbrFlea()
{
	return nbPuce;
}

int DLControler::getSize()
{
	return size;
}

bool DLControler::getData(char* data)
{

	sem_wait(&dataWrited);

	int end;
	sem_getvalue(&gameEnd, &end);

	if(end)
	{
		return true;
	}

	for (int i = 0; i < size*size; ++i)
	{
		data[i] = this->data[i];
	}
	sem_post(&dataReaded);

	return false;
}

void DLControler::doWork()
{
	int nbTour = 1;
	int stopValue;
	while(true)
	{
		sem_getvalue(&stop, &stopValue);
		if(stopValue != 0)
		{
			break;
		}
		if (listPuce.size() == 0)
		{
			sem_post(&gameEnd);
			sem_post(&dataWrited);
			break;
		}
		if(DLpuce::getNbrPuceWaiting() == (int)listPuce.size())
		{
//			std::cout << "tour : " << nbTour << std::endl;
//			std::cout << "Puce : " << listPuce.size() << std::endl;
//			this->map.show();
//			//usleep(100000);
//			system("clear");

			sem_wait(&dataReaded);

			sem_getvalue(&stop, &stopValue);
			if(stopValue != 0)
			{
				break;
			}

			this->map.writeData(data);

			sem_post(&dataWrited);


			for (unsigned int i = 0; i < listPuceDog.size(); ++i)
			{
				DLpuce *puce = listPuceDog[i];
				puce->join();

				int range = 0;
				while(puce != listPuce[range])
				{
					range++;
				}
				listPuce.erase(listPuce.begin()+range);
			}
			listPuceDog.clear();
			DLpuce::resetPuceWaitCounter();
			for (unsigned int i = 0; i < listPuce.size(); ++i)
			{
				listPuce[i]->go();
			}
			nbTour++;
		}
	}
}

DLControler::~DLControler()
{

	for (unsigned int i = 0; i < listSavePuce.size(); ++i)
	{
		DLpuce *puce = listSavePuce[i];
		delete puce;
		puce = NULL;
	}

	delete[] data;
	sem_destroy(&semPuceDog);
	sem_destroy(&dataReaded);
	sem_destroy(&dataWrited);
}

void DLControler::join()
{
	sem_post(&stop);
	sem_post(&this->dataReaded);
	DLthread::join();
}

void DLControler::setPuce(int jumpX, int jumpY, DLpuce *puce)
{
	if(map.jumpPuce(jumpX,jumpY,puce))
	{
		sem_wait(&semPuceDog);
		listPuceDog.push_back(puce);
		sem_post(&semPuceDog);
	}
}

