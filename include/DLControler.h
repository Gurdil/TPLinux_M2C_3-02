/*
 * DLControler.h
 *
 *  Created on: Dec 1, 2014
 *      Author: gurdil
 */

#ifndef SRC_DLCONTROLER_H_
#define SRC_DLCONTROLER_H_

#include <semaphore.h>
#include <vector>
#include "map.h"
#include "puce.h"
#include "thread.h"

/**
 * @author PHILIPPE Jean-Baptiste
 *
 **/
class DLControler: public DLthread
{
public:
	/**
	 * @fn DLControler(int size)
	 * Constructor
	 * @param size size of the map
	 */
	DLControler(int size);
	virtual ~DLControler();
	/**
	 * @fn void setPuce(int jumpX, int jumpY, DLpuce *puce)
	 * Move a flea
	 * @param jumpX the movement of the flea on X
	 * @param jumpY the movement of the flea on Y
	 * @param puce theflea to move
	 */
	void setPuce(int jumpX, int jumpY, DLpuce *puce);
	/**
	 * @fn bool getData(char* data)
	 * wait until the data is available
	 * @return true if the play is finished
	 */
	bool getData(char* data);
	/**
	 * @fn int getNbrFlea()
	 * @return the number of flea created
	 */
	int getNbrFlea();
	/**
	 * @fn void join()
	 * the thread will be terminated
	 */
	void join();
	/**
	 * @fn int getSize()
	 * @return size of the map
	 */
	int getSize();

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
