//
// App.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 17:36:58 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 14:27:48 2016 Victorien LE COUVIOUR--TUFFET
//

#include <fstream>
#include <iostream>
#include "App.hpp"
#include "ToolBox.hpp"

App::App(void) : _vm(NULL) {}

App::~App(void)
{
  if (_vm)
    delete (_vm);
}

void
App::run(int const argc, char *argv[])
{
  std::ifstream		ifs;
  std::istream *	is;

  if (argc >= 2)
    {
      ifs.open(argv[1]);
      if (!ifs.is_open())
	throw ToolBox::Exception(std::string("Unable to open file \"" +
					     std::string(argv[1]) + "\"").c_str());
      is = &ifs;
    }
  else
    is = &std::cin;
  _vm = new VirtualMachine(*is, std::cout);
  _vm->run();
  if (is == &ifs)
    {
      ifs.close();
      if (ifs.is_open())
	throw ToolBox::Exception(std::string("Unable to close file \"" +
					     std::string(argv[1]) + "\"").c_str());
    }
}
