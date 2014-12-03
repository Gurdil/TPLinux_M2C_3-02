/*
 * DLWindow.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: gurdil
 */

#include "DLWindow.h"

DLWindow::DLWindow() :
	pixBufDog(Gdk::Pixbuf::create_from_file("./res/dog.png", 50, 50,true)),
	pixBufFlea(Gdk::Pixbuf::create_from_file("./res/flea.png", 50, 50,true)),
	pictureDog(pixBufDog),
	pictureFlea(pixBufFlea),
	grid()
{
	set_border_width(10);
	add(grid);

	grid.attach(pictureDog, 0,0,1,1);
	pictureDog.set_hexpand(true);
	pictureDog.set_vexpand(true);

	grid.attach(pictureFlea, 1,1,1,1);
	pictureFlea.set_hexpand(true);
	pictureFlea.set_vexpand(true);

	grid.remove(*grid.get_child_at(0,0));
	grid.attach(pictureDog, 2,2,1,1);


	this->show_all_children(true);
}

DLWindow::~DLWindow() {
	// TODO Auto-generated destructor stub
}

