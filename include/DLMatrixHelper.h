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

/**
 * @author PHILIPPE Jean-Baptiste
 * <p>
 * 		This class provide usefull method to manage matrix
 * <p>
 **/
class DLMatrixHelper
{
public:
	/**
	 * @fn DLMatrixHelper(int size)
	 * Constructor
	 * @param size Size of the matrix
	 */
	DLMatrixHelper(int size);
	virtual ~DLMatrixHelper();
protected:
	/**
	 * Size of the matrix
	 */
	int size;
	/**
	 * @fn int convert(int i, int j)
	 * Convert a 2D matrix index to a tab index
	 * @param i i
	 * @param j j
	 */
	int convert(int i, int j);
	/**
	 * @fn int convertLin(int range)
	 * @param range range
	 * @return line of the matrix
	 */
	int convertLin(int range);
	/**
	 * @fn int convertCol(int range)
	 * @param range range
	 * @return colon of the matrix
	 */
	int convertCol(int range);
};

#endif /* SRC_DLMATRIXHELPER_H_ */
