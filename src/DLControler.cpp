/*
 * DLControler.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: gurdil
 */

#include "DLControler.h"

DLControler::DLControler(int size) : map(size),listPuce()
{
	nbPuce = (double)size/100*10;

	std::vector<DLpuce*> listPuce;
	for (int i = 0; i < nbPuce; ++i)
	{
		DLpuce * puce = new DLpuce(this);
		listPuce.push_back(puce);
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
		if (nbTour == 2)
		{
			break;
		}
		if(DLpuce::getNbrPuceWaiting() == nbPuce)
		{
			std::cout << "tour : " << nbTour << std::endl;

			DLpuce::resetPuceWaitCounter();
			for (int i = 0; i < nbPuce; ++i)
			{
				listPuce[i]->go();
			}
			nbTour++;
		}
		else
		{
			usleep(1000);
		}
	}

	this->map.show();

}

DLControler::~DLControler()
{
	for (unsigned int i = 0; i < listPuce.size(); ++i)
	{
		DLpuce *puce = listPuce[i];
		puce->join();
		delete puce;
		puce = NULL;
	}
}

void DLControler::setPuce(int jumpX, int jumpY, DLpuce *puce)
{
	//TODO
}

