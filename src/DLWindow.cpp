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
	tab{'_','F','_','_','_','_','_','_','_','_',
		'_','D','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','_','_','_','_','_','F','_','_',
		'_','_','_','_','_','_','_','_','_','_',
		'_','_','F','_','_','F','_','_','_','_',
		'_','_','_','_','_','_','_','F','_','_',
		'_','F','_','_','_','_','_','_','_','_',
		'_','_','_','F','_','_','_','_','_','_',
		'_','_','F','_','_','F','_','_','_','F',}
{
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
					grid.attach(*listPixVoid[this->convert(i,j)], i,j,1,1);
					break;
				case 'D':
					grid.attach(*pictureDog, i,j,1,1);
					break;
				case 'F':
					grid.attach(*listPixFlea[nbFleaAttached], i,j,1,1);
					nbFleaAttached++;
					break;
			}
		}
	}
}



Gtk::Image* DLWindow::createImage(const Glib::RefPtr<Gdk::Pixbuf> &pixBufDog)
{
	Gtk::Image *result = new Gtk::Image(pixBufDog);
	result->set_hexpand(true);
	result->set_vexpand(true);
	result->override_background_color(Gdk::RGBA("white"));
	result->set_margin_bottom(1);
	result->set_margin_top(1);
	result->set_margin_left(1);
	result->set_margin_right(1);
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
