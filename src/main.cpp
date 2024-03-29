//============================================================================
// Name        : TP_Linux.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "DLControler.h"
#include "DLWindow.h"
#include <iostream>

#ifdef GRAPHIC
#include <gtkmm/application.h>
#endif
using namespace std;

#ifdef GRAPHIC
int main(int argc, char *argv[])
{
#else
int main()
{
#endif
	#ifdef GRAPHIC

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

	#endif

	int size = SIZE;

	DLControler controler(size);

	controler.start();

	#ifdef GRAPHIC

	DLWindow window(&controler);

	return app->run(window);

	#else

	char *data = new char[size*size];
	int turn = 0;
	while(!controler.getData(data))
	{
		std::cout << "Turn : " << turn << std::endl;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				std::cout << data[i*size + j];
			}
			std::cout <<std::endl;
		}

		std::cout <<std::endl;
		std::cout <<std::endl;
		turn++;
		system("clear");
	}

	std::cout << "Fin de partie !" << std::endl;

	delete[] data;

	#endif

}
