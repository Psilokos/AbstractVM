//
// Store.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:53:32 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 00:08:46 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Store.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Store::Store(Component::CPU::Instruction::Argument const & arg,
	       std::vector<IOperand *> & registers) : _arg(arg), _registers(registers) {}
  Store::~Store(void) {}

  bool
  Store::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("store instruction on empty stack");
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
	if (_registers[_arg.reg])
	  delete (_registers[_arg.reg]);
	_registers[_arg.reg] = inOperands.first;
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Pop;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 3) ? (false) : true);
  }
}
