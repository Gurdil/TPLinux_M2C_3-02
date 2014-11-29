/*
 * puce.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */
#include "thread.h"

#ifndef PUCE_H_
#define PUCE_H_

class puce: public DLthread
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

protected:
	virtual void doWork();

};

#endif /* PUCE_H_ */
