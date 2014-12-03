/*
 * DLControler.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: gurdil
 */

#include "DLControler.h"

DLControler::DLControler(int size) : map(size),listPuce(),listSavePuce(),listPuceDog()
{
	sem_init(&semPuceDog, 0, 1);

	nbPuce = (double)(size*size)/100*10;
	//nbPuce = 1;

	std::vector<DLpuce*> listPuce;
	for (int i = 0; i < nbPuce; ++i)
	{
		DLpuce * puce = new DLpuce(this);
		listPuce.push_back(puce);
		listSavePuce.push_back(puce);
		map.setPuce(puce);
	}

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->start();
	}

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->go();
	}

	int nbTour = 1;
	while(true)
	{
		if (listPuce.size() == 0)
		{
			std::cout << "Fin de partie !" << std::endl;
			break;
		}
		if(DLpuce::getNbrPuceWaiting() == (int)listPuce.size())
		{
			std::cout << "tour : " << nbTour << std::endl;
			std::cout << "Puce : " << listPuce.size() << std::endl;
			this->map.show();
			//usleep(100000);
			system("clear");

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

	sem_destroy(&semPuceDog);
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

