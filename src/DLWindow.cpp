/*
 * DLWindow.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: gurdil
 */

#include "DLWindow.h"

DLWindow::DLWindow(int size) :
	DLMatrixHelper(size),
	pixBufDog(Gdk::Pixbuf::create_from_file("./res/dog.png", 50, 50,false)),
	pixBufFlea(Gdk::Pixbuf::create_from_file("./res/flea.png", 50, 50,false)),
	pixBufVoid(Gdk::Pixbuf::create_from_file("./res/void.png", 50, 50,false)),
	grid(),
	size(size),
	nbFlea(10),
	tab{'_','D','_','F','_','_','_','_','_','_',
		'_','_','_','F','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','F','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_'},
		nbRun(0)
{

	sigc::slot<bool> my_slot = sigc::bind(sigc::mem_fun(*this, &DLWindow::on_timeout), 1);
	sigc::connection conn = Glib::signal_timeout().connect(my_slot, 1000);

	set_border_width(10);
	add(grid);
	grid.override_background_color(Gdk::RGBA("black"));

	for (int i = 0; i < size*size; ++i)
	{
		listPixVoid.push_back(this->createImage(pixBufVoid));
	}

	for (int i = 0; i < nbFlea; ++i)
	{
		listPixFlea.push_back(this->createImage(pixBufFlea));
	}

	pictureDog = this->createImage(pixBufDog);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			grid.attach(*listPixVoid[this->convert(i,j)], i,j,1,1);
		}
	}

	this->flushGrid();
	this->update(tab);

	this->show_all_children(true);
}

bool DLWindow::on_timeout(int timer_number)
{
	if(nbRun%2 == 0)
	{
		tab[55] = 'F';
	}
	else
	{
		tab[55] = '_';
	}

	this->flushGrid();
	this->update(tab);

	nbRun++;
	if(nbRun == 4)
	{
		return false;
	}
	else
	{
		return true;
	}
}

DLWindow::~DLWindow()
{
	for (unsigned int i = 0; i < listPixVoid.size(); ++i)
	{
		delete listPixVoid[i];
	}

	for (unsigned int i = 0; i < listPixFlea.size(); ++i)
	{
		delete listPixFlea[i];
	}

	delete pictureDog;
}

void DLWindow::update(char *data)
{
	int nbFleaAttached = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			char a = data[this->convert(i,j)];
			switch (a)
			{
				case '_':
					grid.attach(*listPixVoid[this->convert(i,j)], j,i,1,1);
					break;
				case 'D':
					grid.attach(*pictureDog, j,i,1,1);
					break;
				case 'F':
					grid.attach(*listPixFlea[nbFleaAttached], j,i,1,1);
					nbFleaAttached++;
					break;
			}
		}
	}
}



Gtk::Image* DLWindow::createImage(const Glib::RefPtr<Gdk::Pixbuf> &pixBuf)
{
	Gtk::Image *result = new Gtk::Image(pixBuf);
	result->set_hexpand(true);
	result->set_vexpand(true);
	result->override_background_color(Gdk::RGBA("white"));
	result->set_margin_bottom(1);
	result->set_margin_top(1);
	result->set_margin_left(1);
	result->set_margin_right(1);
	result->show();
	return result;
}

void DLWindow::flushGrid()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			Widget* widget = grid.get_child_at(i,j);

			if(widget != NULL)
			{
				grid.remove(*widget);
			}
		}
	}
}
