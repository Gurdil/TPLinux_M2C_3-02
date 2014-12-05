/*
 * DLMatrixHelper.h
 *
 *  Created on: Dec 5, 2014
 *      Author: gurdil
 */

#ifndef SRC_DLMATRIXHELPER_H_
#define SRC_DLMATRIXHELPER_H_

#include <string>
#include <stdexcept>

class DLMatrixHelper
{
public:
	DLMatrixHelper(int size);
	virtual ~DLMatrixHelper();
protected:
	int size;
	int convert(int i, int j);
	int convertLin(int range);
	int convertCol(int range);
};

#endif /* SRC_DLMATRIXHELPER_H_ */
