//
// main.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 17:30:32 2016 Victorien LE COUVIOUR--TUFFET
// Last update Mon Jul 18 13:19:47 2016 Victorien LE COUVIOUR--TUFFET
//

#include <iostream>
#include <stdlib.h>
#include "App.hpp"
#include "ToolBox.hpp"

int	main(int argc, char *argv[])
{
  App	app;

  try
    {
      app.run(argc, argv);
    }
  catch (ToolBox::Exception const & e)
    {
      std::cerr << "AbstractVM: " << e.what() << std::endl;
      return (84);
    }
  catch (...)
    {
      std::cerr << "Unknown exception raised" << std::endl;
      return (84);
    }
  return (EXIT_SUCCESS);
}
