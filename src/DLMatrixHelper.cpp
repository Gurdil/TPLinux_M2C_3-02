/*
 * DLMatrixHelper.cpp
 *
 *  Created on: Dec 5, 2014
 *      Author: gurdil
 */

#include "DLMatrixHelper.h"

DLMatrixHelper::DLMatrixHelper(int size): size(size)
{
}

DLMatrixHelper::~DLMatrixHelper()
{
}

int DLMatrixHelper::convertLin(int range)
{
	return (range - this->convertCol(range))/size;
}

int DLMatrixHelper::convertCol(int range)
{
	return range%size;
}

int DLMatrixHelper::convert(int i, int j)
{
	if(i<0 || i>(size-1) || j<0 || j>(size-1))
	{
		throw std::out_of_range("Out of range in map : "+std::to_string (i)+", "+std::to_string (j));
	}
	return i*size + j;
}
