/*
 * map.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#ifndef MAP_H_
#define MAP_H_


#include <chrono>
#include <random>
#include <stdexcept>
#include <iostream>
#include <complex>
#include <string>
#include "case.h"

class DLpuce;

/**
 * @author PHILIPPE Jean-Baptiste
 *	<p>
 * 		Represent the map
 * 	<p>
 **/
class DLmap
{
public:
	/**
	 * @fn DLmap(int size)
	 * Constructor
	 * @param size The size of the map the map is square
	 */
	DLmap(int size);
	virtual ~DLmap();
	/**
	 * @fn void show()
	 * @deprecated not used anymore
	 */
	void show();
	/**
	 * @fn void setPuce(DLpuce *puce)
	 * The flea is inserted on the map randomly
	 * @param puce the flea to insert
	 */
	void setPuce(DLpuce *puce);
	/**
	 * @fn bool jumpPuce(int jumpX, int jumpY, DLpuce *puce)
	 * Move a flea
	 * @param jumpX the movement of the flea on X
	 * @param jumpY the movement of the flea on Y
	 * @param puce theflea to move
	 * @return true if the flea is on the dog
	 */
	bool jumpPuce(int jumpX, int jumpY, DLpuce *puce);
	/**
	 * @fn void writeData(char *data)
	 * the state of the map will be copied in the parameter data
	 * @param data the tab were the data will be written
	 */
	void writeData(char *data);

private:
	int size;
	DLCase *cases;
	std::default_random_engine generator;

	int convert(int i, int j);
	int convertLin(int range);
	int convertCol(int range);
	bool setPuce(int line, int col, DLpuce *puce,int range);
	int dogAuraSize;
};

#endif /* MAP_H_ */
