//============================================================================
// Name        : TP_Linux.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "puce.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);

	std::uniform_int_distribution<int> distribution(1,10);

	std::cout << "some random numbers between 1 and 10: ";
	for (int i=0; i<10; ++i)
		std::cout << distribution(generator) << " ";

	std::cout << std::endl;

	const int nbPuce = 10;
	std::vector<DLpuce*> listPuce;
	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce.push_back(new DLpuce());
	}

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->start();
	}

	for (int i = 0; i < nbPuce; ++i)
	{
		listPuce[i]->go();
	}

	int nbTour = 0;
	while(true)
	{
		if (nbTour == 5)
		{
			break;
		}
		if(listPuce[0]->getNbrPuceWaiting() == nbPuce)
		{
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


	usleep(1000000);
	for (unsigned int i = 0; i < listPuce.size(); ++i)
	{
		DLpuce *puce = listPuce[i];
		puce->join();
		delete puce;
		puce = NULL;
	}
	return 0;
}
