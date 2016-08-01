//
// Print.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:58:57 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:53:33 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Print.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Print::Print(void) {}
  Print::~Print(void) {}

  bool
  Print::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("print instruction on empty stack");
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
	if (inOperands.first->getType() != eOperandType::INT8)
	  throw ToolBox::Exception("the top stack value is not an 8-bit integer");
	_outString += static_cast<char>(stoi(inOperands.first->toString()));
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetSB,
							   Component::ComponentType::ChipsetNB));
	_communications.push_back(Component::Communication(Component::ComponentType::IO,
							   Component::ComponentType::ChipsetSB));
      }
    return ((_callNb == 3) ? (false) : true);
  }
}
