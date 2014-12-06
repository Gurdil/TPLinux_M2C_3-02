/*
 * DLWindow.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: gurdil
 */

#include "DLWindow.h"


//tab{'_','D','_','F','_','_','_','_','_','_',
//		'_','_','_','F','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','F','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_',
//		'_','_','_','_','_','_','_','_','_','_'},

DLWindow::DLWindow(DLControler *controler) :
	DLMatrixHelper(controler->getSize()),
	controler(controler),
	size(controler->getSize()),
	picSize((Gdk::Screen::get_default()->get_width() < Gdk::Screen::get_default()->get_height() ? Gdk::Screen::get_default()->get_width() : Gdk::Screen::get_default()->get_height()
			- ((Gdk::Screen::get_default()->get_width() < Gdk::Screen::get_default()->get_height() ? Gdk::Screen::get_default()->get_width() : Gdk::Screen::get_default()->get_height()*25)
					/100))/size),
	pixBufDog(Gdk::Pixbuf::create_from_file("./res/dog.png", picSize, picSize,false)),
	pixBufFlea(Gdk::Pixbuf::create_from_file("./res/flea.png", picSize, picSize,false)),
	pixBufVoid(Gdk::Pixbuf::create_from_file("./res/void.png", picSize, picSize,false)),
	pixBufVictory(Gdk::Pixbuf::create_from_file("./res/victory.png")),
	grid(),
	nbFlea(controler->getNbrFlea()),
	box(Gtk::ORIENTATION_VERTICAL),
	nbRun(0),
	buttonStart("Start")
{
	tab = new char[size*size];
	for (int i = 0; i < size*size; ++i)
	{
		tab[i] = '_';
	}

	buttonStart.signal_clicked().connect(sigc::mem_fun(*this, &DLWindow::startButtonClicked));

	set_border_width(10);
	add(box);
	box.pack_start(grid);
	box.pack_start(buttonStart);
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
	pictureVictory = this->createImage(pixBufVictory);
	pictureVictory->show();

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

void DLWindow::startButtonClicked()
{
	sigc::connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &DLWindow::on_timeout), 100);
	buttonStart.set_state(Gtk::StateType::STATE_INSENSITIVE);
}


bool DLWindow::on_timeout()
{
	bool end = controler->getData(tab);

	if(end)
	{
		grid.hide();
		buttonStart.hide();
		box.pack_start(*pictureVictory);
		return false;
	}

	this->flushGrid();
	this->update(tab);

	return true;
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
	delete pictureVictory;
	delete[] tab;

	controler->join();
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
