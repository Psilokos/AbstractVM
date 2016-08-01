//
// Swap.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:49:05 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 00:15:19 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Swap.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Swap::Swap(void) {}
  Swap::~Swap(void) {}

  bool
  Swap::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("the stack strictly has less than two values \
during the execution of a swap instruction");
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
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Pop;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    else if (_callNb == 3)
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
    else if (_callNb == 4)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Pop;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    else if (_callNb == 5)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Push;
	_mmuInstr->arg.operand = inOperands.second;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    else if (_callNb == 6)
      {
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::Push;
	_mmuInstr->arg.operand = inOperands.first;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 7) ? (false) : (true));
  }
}
