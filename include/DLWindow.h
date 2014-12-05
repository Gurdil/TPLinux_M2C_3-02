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
#include <gtkmm/button.h>
#include <vector>
#include "DLMatrixHelper.h"
#include "DLControler.h"

class DLWindow: public Gtk::Window, public DLMatrixHelper
{
public:
	DLWindow(int size, DLControler *controler);
	virtual ~DLWindow();

private:
	DLControler *controler;
	Glib::RefPtr<Gdk::Pixbuf> pixBufDog;
	Glib::RefPtr<Gdk::Pixbuf> pixBufFlea;
	Glib::RefPtr<Gdk::Pixbuf> pixBufVoid;
	Glib::RefPtr<Gdk::Pixbuf> pixBufVictory;
	Gtk::Image *pictureDog;
	Gtk::Image *pictureVictory;
	Gtk::Grid grid;
	int size;
	int nbFlea;
	std::vector<Gtk::Image*> listPixVoid;
	std::vector<Gtk::Image*> listPixFlea;
	char *tab;

	void flushGrid();
	void update(char *data);
	Gtk::Image* createImage(const Glib::RefPtr<Gdk::Pixbuf> &pixBufDog);
	bool on_timeout();
	void startButtonClicked();
	Gtk::Box box;
	int nbRun;
	Gtk::Button buttonStart;
};

#endif /* SRC_DLWINDOW_H_ */
