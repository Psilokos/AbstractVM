//
// Load.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:39:51 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:40:34 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Factory.h"
#include "Load.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Load::Load(Component::CPU::Instruction::Argument const & arg, std::vector<IOperand *> & registers)
    : _arg(arg), _registers(registers) {}
  Load::~Load(void) {}

  bool
  Load::operator()(std::pair<IOperand *, IOperand *> &, bool const)
  {
    if (++_callNb == 1)
      {
	if (!_registers[_arg.reg])
	  throw ToolBox::Exception("load instruction on empty register");
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Push;
	_mmuInstr->arg.operand = Factory::createOperand(_registers[_arg.reg]->getType(),
							_registers[_arg.reg]->toString());
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 2) ? (false) : true);
  }
}
