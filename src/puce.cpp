/*
 * puce.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "puce.h"

puce::puce() :
		DLthread()
{
	posX = 0;
	posY = 0;
	display = 'P';
}

puce::~puce()
{

}

void puce::doWork()
{
	cout << "I'm a puce !" << endl;
	usleep(1000000);
}

