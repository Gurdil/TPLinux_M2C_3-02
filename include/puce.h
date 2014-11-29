/*
 * puce.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */
#include "thread.h"

#ifndef PUCE_H_
#define PUCE_H_

class puce: DLthread
{
public:
	puce();
	virtual ~puce();

	int get_posX();
	int get_posY();

private:

	int posX;
	int posY;
	char display;

};

#endif /* PUCE_H_ */
