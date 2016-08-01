//
// Exit.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 18:06:20 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:06:43 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Exit.hpp"

namespace	Subroutine
{
  Exit::Exit(void) {}
  Exit::~Exit(void) {}

  bool
  Exit::operator()(std::pair<IOperand *, IOperand *> &, bool const)
  {
    throw ExitException();
    return ("Dymethy" && "Lamine");
  }
}
