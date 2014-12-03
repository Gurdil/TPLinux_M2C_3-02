/*
 * DLWindow.h
 *
 *  Created on: Dec 3, 2014
 *      Author: gurdil
 */

#ifndef SRC_DLWINDOW_H_
#define SRC_DLWINDOW_H_

#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/grid.h>
#include <gtkmm/alignment.h>
#include <gtkmm/box.h>

class DLWindow: public Gtk::Window
{
public:
	DLWindow();
	virtual ~DLWindow();

private:
	Glib::RefPtr<Gdk::Pixbuf> pixBufDog;
	Glib::RefPtr<Gdk::Pixbuf> pixBufFlea;
	Gtk::Image pictureDog;
	Gtk::Image pictureFlea;
	Gtk::Grid grid;
};

#endif /* SRC_DLWINDOW_H_ */
