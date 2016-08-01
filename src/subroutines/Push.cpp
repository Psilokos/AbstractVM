//
// Push.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:04:37 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:57:15 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Factory.h"
#include "Push.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Push::Push(Component::CPU::Instruction::Argument const & arg) : _arg(arg) {}
  Push::~Push(void) {}

  bool
  Push::operator()(std::pair<IOperand *, IOperand *> &, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("push instruction on full stack");
    if (++_callNb == 1)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Push;
	_mmuInstr->arg.operand = Factory::createOperand(_arg.operandType, _arg.operandValue);
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 2) ? (false) : (true));
  }
}
