//
// Operation.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Tue Jul 19 18:46:00 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 14:25:50 2016 Victorien LE COUVIOUR--TUFFET
//

#include "IComponent.hpp"
#include "Operation.hpp"
#include "ToolBox.hpp"

namespace	Subroutine
{
  Operation::Operation(OperationType const & opType) : _opType(opType)
  {
    _operations[OperationType::Add] = &Operation::_add;
    _operations[OperationType::Sub] = &Operation::_sub;
    _operations[OperationType::Mul] = &Operation::_mul;
    _operations[OperationType::Div] = &Operation::_div;
    _operations[OperationType::Mod] = &Operation::_mod;
  }

  Operation::~Operation(void) {}

  bool
  Operation::operator()(std::pair<IOperand *, IOperand *> & inOperands, bool const exceptionRaised)
  {
    if (exceptionRaised)
      throw ToolBox::Exception("the stack strictly has less than two values \
during the execution of an arithmetical instruction");
    if (++_callNb == 1 || _callNb == 3)
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
    else if (_callNb == 2 || _callNb == 4)
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
	_mmuInstr->arg.operand = (this->*_operations[_opType])(*inOperands.first, *inOperands.second);
	_communications.push_back(Component::Communication(Component::ComponentType::ChipsetNB,
							   Component::ComponentType::CPU));
	_communications.push_back(Component::Communication(Component::ComponentType::MMU,
							   Component::ComponentType::ChipsetNB));
      }
    return ((_callNb == 6) ? (false) : (true));
  }

  /*
  ** private methods
  */

  IOperand *	Operation::_add(IOperand const & a, IOperand const & b)	{ return (a + b); }
  IOperand *	Operation::_sub(IOperand const & a, IOperand const & b)	{ return (a - b); }
  IOperand *	Operation::_mul(IOperand const & a, IOperand const & b)	{ return (a * b); }
  IOperand *	Operation::_div(IOperand const & a, IOperand const & b)	{ return (a / b); }
  IOperand *	Operation::_mod(IOperand const & a, IOperand const & b)	{ return (a % b); }
}
