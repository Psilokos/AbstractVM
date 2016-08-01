//
// Dup.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:39:24 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:01:52 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Dup.hpp"
#include "Factory.h"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Dup::Dup(void) {}
  Dup::~Dup(void) {}

  bool
  Dup::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("dup instruction on empty stack");
    if (++_callNb == 1)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Top;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::MMU));
	_communications.push_back(Component::Communication(Component::ComponentType::CPU,
							   Component::ComponentType::ChipsetNB));
      }
    else if (_callNb == 2)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Push;
	_mmuInstr->arg.operand = Factory::createOperand(inOperands.first->getType(),
							inOperands.first->toString());
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 3) ? (false) : (true));
  }
}
