//
// Assert.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 13:40:26 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 17:10:09 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Assert.hpp"
#include "Factory.h"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Assert::Assert(Component::CPU::Instruction::Argument const & arg) : _arg(arg) {}
  Assert::~Assert(void) {}

  bool
  Assert::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("assert instruction on empty stack");
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
	inOperands.second = Factory::createOperand(_arg.operandType, _arg.operandValue);
	if (*inOperands.first != *inOperands.second)
	  throw ToolBox::Exception("an assert instruction was not verified");
	delete (inOperands.second);
      }
    return ((_callNb == 2) ? (false) : (true));
  }
}
