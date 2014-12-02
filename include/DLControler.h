/*
 * DLControler.h
 *
 *  Created on: Dec 1, 2014
 *      Author: gurdil
 */

#ifndef SRC_DLCONTROLER_H_
#define SRC_DLCONTROLER_H_

#include <stdlib.h>
#include <semaphore.h>
#include "map.h"
#include "puce.h"

class DLControler
{
public:
	DLControler(int size);
	virtual ~DLControler();
	void setPuce(int jumpX, int jumpY, DLpuce *puce);

private:
	DLmap map;
	int nbPuce;
	std::vector<DLpuce*> listPuce;
	std::vector<DLpuce*> listPuceDog;
	sem_t semPuceDog;
};

#endif /* SRC_DLCONTROLER_H_ */
