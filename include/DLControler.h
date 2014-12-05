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
#include <vector>
#include "map.h"
#include "puce.h"
#include "thread.h"

class DLControler: public DLthread
{
public:
	DLControler(int size);
	virtual ~DLControler();
	void setPuce(int jumpX, int jumpY, DLpuce *puce);
	bool getData(char* data);
	int getNbrFlea();
	void join();

private:
	int size;
	DLmap map;
	int nbPuce;
	std::vector<DLpuce*> listPuce;
	std::vector<DLpuce*> listSavePuce;
	std::vector<DLpuce*> listPuceDog;
	sem_t semPuceDog;
	virtual void doWork();
	char* data;
	sem_t dataReaded;
	sem_t dataWrited;
	sem_t gameEnd;
	sem_t stop;
};

#endif /* SRC_DLCONTROLER_H_ */
