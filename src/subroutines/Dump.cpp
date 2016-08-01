//
// Dump.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 13:00:28 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 14:25:17 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Dump.hpp"

namespace	Subroutine
{
  Dump::Dump(void) {}
  Dump::~Dump(void) {}

  bool
  Dump::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (!exceptionRaised)
      {
	if (inOperands.first)
	  {
	    _outString = inOperands.first->toString();
	    inOperands.first = NULL;
	    _communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							       Component::ComponentType::CPU));
	    _communications.push_back(Component::Communication(Component::ComponentType::ChipsetSB,
							       Component::ComponentType::ChipsetNB));
	    _communications.push_back(Component::Communication(Component::ComponentType::IO,
							       Component::ComponentType::ChipsetSB));
	  }
	_mmuInstr = new Component::MMU::Instruction();
	_mmuInstr->opcode = Component::MMU::Instruction::Opcode::At;
	_mmuInstr->arg.idx = _callNb++;
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::MMU));
	_communications.push_back(Component::Communication(Component::ComponentType::CPU,
							   Component::ComponentType::ChipsetNB));
      }
    return (!exceptionRaised);
  }
}
