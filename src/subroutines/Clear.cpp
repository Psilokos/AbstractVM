//
// Clear.cpp for  in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:37:34 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:28:49 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Clear.hpp"

namespace	Subroutine
{
  Clear::Clear(void) {}
  Clear::~Clear(void) {}

  bool
  Clear::operator()(std::pair<IOperand *, IOperand *> &, bool const)
  {
    if (++_callNb == 1)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Clear;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 2) ? (false) : (true));
  }
}
