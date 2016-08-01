//
// ASubroutine.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:21:02 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:18:05 2016 Victorien LE COUVIOUR--TUFFET
//

#include "ASubroutine.hpp"

namespace	Subroutine
{
  ASubroutine::ASubroutine(void) : _callNb(0), _mmuInstr(NULL) {}
  ASubroutine::~ASubroutine(void) { if (_mmuInstr) delete (_mmuInstr); }

  std::list<Component::Communication>
  ASubroutine::getCommunications(void)
  {
    std::list<Component::Communication>	communications = _communications;

    _communications.clear();
    return (communications);
  }

  Component::MMU::Instruction *
  ASubroutine::getMMUInstruction(void)
  {
    Component::MMU::Instruction * const	mmuInstr = _mmuInstr;

    _mmuInstr = NULL;
    return (mmuInstr);
  }

  std::string
  ASubroutine::getOutString(void)
  {
    std::string const	outString = _outString;

    _outString.clear();
    return (outString);
  }
}
