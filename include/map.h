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
 *
 **/
class DLmap
{
public:
	DLmap(int size);
	virtual ~DLmap();
	void show();
	void setPuce(DLpuce *puce);
	bool jumpPuce(int jumpX, int jumpY, DLpuce *puce);
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
