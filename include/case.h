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
 * 	@author PHILIPPE Jean-Baptiste
 *	<p>
 * 		Represent a box of the grid
 * 	<p>
 **/
class DLCase
{
public:
	/**
	 * @fn DLCase()
	 * Constructor
	 */
	DLCase();
	virtual ~DLCase();
	/**
	 * @fn void setDog()
	 * The box contain the dog
	 */
	void setDog();
	/**
	 * @fn bool getDog()
	 * test if the box contain the dog
	 */
	bool getDog();
	/**
	 * @fn void setPound(char pound)
	 * Set the value of the dog aura
	 * @param pound value of the aura
	 */
	void setPound(char pound);
	/**
	 * @fn char getPound()
	 * Get the value of the dog aura
	 */
	char getPound();
	/**
	 * @fn DLpuce* getPuce()
	 * Get the flea contain on the box
	 * @return the flea or NULL if the box is empty
	 */
	DLpuce* getPuce();
	/**
	 * @fn void setPuce(DLpuce *puce)
	 * Put a flea in the box
	 * @param puce the flea to put in the box
	 */
	void setPuce(DLpuce *puce);

private:
	bool dog;
	DLpuce *puce;
	unsigned char pound;
	sem_t sem;

};

#endif /* CASE_H_ */
