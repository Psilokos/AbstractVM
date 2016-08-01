//
// Pop.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:33:32 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:50:48 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Pop.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Pop::Pop(void) {}
  Pop::~Pop(void) {}

  bool
  Pop::operator()(std::pair<IOperand *, IOperand *> &, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("pop instruction on an empty stack");
    if (++_callNb == 1)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Pop;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 2) ? (false) : (true));
  }
}
