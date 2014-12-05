/*
 * DLWindow.h
 *
 *  Created on: Dec 3, 2014
 *      Author: gurdil
 */

#ifndef SRC_DLWINDOW_H_
#define SRC_DLWINDOW_H_

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/grid.h>
#include <gtkmm/alignment.h>
#include <gtkmm/box.h>
#include <vector>
#include "DLMatrixHelper.h"

class DLWindow: public Gtk::Window, public DLMatrixHelper
{
public:
	DLWindow(int size);
	virtual ~DLWindow();

private:
	Glib::RefPtr<Gdk::Pixbuf> pixBufDog;
	Glib::RefPtr<Gdk::Pixbuf> pixBufFlea;
	Glib::RefPtr<Gdk::Pixbuf> pixBufVoid;
	Gtk::Image *pictureDog;
	Gtk::Grid grid;
	int size;
	int nbFlea;
	std::vector<Gtk::Image*> listPixVoid;
	std::vector<Gtk::Image*> listPixFlea;
	char tab[10*10];

	void flushGrid();
	void update(char *data);
	Gtk::Image* createImage(const Glib::RefPtr<Gdk::Pixbuf> &pixBufDog);
	bool on_timeout(int timer_number);
	int nbRun;
};

#endif /* SRC_DLWINDOW_H_ */
