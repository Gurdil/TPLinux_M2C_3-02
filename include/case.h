/*
 * Case.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#ifndef CASE_H_
#define CASE_H_
#include <semaphore.h>
#include "puce.h"

/**
 * @author PHILIPPE Jean-Baptiste
 *
 **/
class DLCase
{
public:
	DLCase();
	virtual ~DLCase();
	void setDog();
	bool getDog();
	void setPound(char pound);
	char getPound();
	DLpuce* getPuce();
	void setPuce(DLpuce *puce);

private:
	bool dog;
	DLpuce *puce;
	unsigned char pound;
	sem_t sem;

};

#endif /* CASE_H_ */
