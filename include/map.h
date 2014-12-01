/*
 * map.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#ifndef MAP_H_
#define MAP_H_

#include "case.h"
#include <chrono>
#include <random>
#include <stdexcept>
#include <iostream>
#include <complex>
#include <string>

class DLpuce;

class DLmap
{
public:
	DLmap(int size);
	virtual ~DLmap();
	void show();
	void setPuce(DLpuce *puce);
	bool setPuce(int line, int col, DLpuce *puce);

private:
	int size;
	DLCase *cases;
	std::default_random_engine generator;

	int convert(int i, int j);
	int dogAuraSize;
};

#endif /* MAP_H_ */
