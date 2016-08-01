//
// CPU.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 14:49:11 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 18:06:59 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Assert.hpp"
#include "Chipset.hpp"
#include "Clear.hpp"
#include "CPU.hpp"
#include "Dup.hpp"
#include "Dump.hpp"
#include "Exit.hpp"
#include "Load.hpp"
#include "Operation.hpp"
#include "Pop.hpp"
#include "Print.hpp"
#include "Push.hpp"
#include "Store.hpp"
#include "Swap.hpp"

namespace	Component
{
  CPU::CPU(void) : _registers(16), _mmuInstr(NULL), _subroutine(NULL)
  {
    _instructions[CPU::Instruction::Opcode::Push] = &CPU::_push;
    _instructions[CPU::Instruction::Opcode::Pop] = &CPU::_pop;
    _instructions[CPU::Instruction::Opcode::Clear] = &CPU::_clear;
    _instructions[CPU::Instruction::Opcode::Dup] = &CPU::_dup;
    _instructions[CPU::Instruction::Opcode::Swap] = &CPU::_swap;
    _instructions[CPU::Instruction::Opcode::Dump] = &CPU::_dump;
    _instructions[CPU::Instruction::Opcode::Assert] = &CPU::_assert;
    _instructions[CPU::Instruction::Opcode::Add] = &CPU::_add;
    _instructions[CPU::Instruction::Opcode::Sub] = &CPU::_sub;
    _instructions[CPU::Instruction::Opcode::Mul] = &CPU::_mul;
    _instructions[CPU::Instruction::Opcode::Div] = &CPU::_div;
    _instructions[CPU::Instruction::Opcode::Mod] = &CPU::_mod;
    _instructions[CPU::Instruction::Opcode::Load] = &CPU::_load;
    _instructions[CPU::Instruction::Opcode::Store] = &CPU::_store;
    _instructions[CPU::Instruction::Opcode::Print] = &CPU::_print;
    _instructions[CPU::Instruction::Opcode::Exit] = &CPU::_exit;
    _inOperands.first = NULL;
    _inOperands.second = NULL;
  }

  CPU::~CPU(void)
  {
    for (auto it = _registers.begin(); it != _registers.end(); ++it)
      if (*it)
	delete (*it);
    if (_mmuInstr)
      {
	if (_mmuInstr->arg.operand)
	  delete (_mmuInstr->arg.operand);
	delete (_mmuInstr);
      }
    if (_subroutine)
      delete (_subroutine);
  }

  std::list<Component::Communication> &	CPU::getCommunications(void)	{ return (_communications); }

  IComponent &
  CPU::operator<<(IComponent & nb)
  {
    Chipset::NorthBridge &	northBridge = dynamic_cast<Chipset::NorthBridge &>(nb);
    CPU::Instruction const *	instr;
    IOperand *			operand;

    northBridge >> instr;
    northBridge >> operand;
    if (instr)
      {
	_arg = instr->arg;
	(this->*_instructions[instr->opcode])();
	delete (instr);
      }
    else if (operand)
      {
	if (!_inOperands.first)
	  _inOperands.first = operand;
	else if (!_inOperands.second)
	  _inOperands.second = operand;
      }
    return (*this);
  }

  void
  CPU::operator>>(std::list<Communication> & communications)
  {
    communications = _communications;
    _communications.clear();
  }

  MMU::Instruction const * &
  CPU::operator>>(MMU::Instruction const * & mmuInstr)
  {
    mmuInstr = _mmuInstr;
    _mmuInstr = NULL;
    return (mmuInstr);
  }

  std::string &
  CPU::operator>>(std::string & outString)
  {
    outString = _outString;
    _outString.clear();
    return (outString);
  }

  bool	CPU::operator()(bool const exceptionRaised)
  {
    bool const	ret = (*_subroutine)(_inOperands, exceptionRaised);

    _communications = _subroutine->getCommunications();
    _mmuInstr = _subroutine->getMMUInstruction();
    _outString = _subroutine->getOutString();
    if (!ret)
      {
	_inOperands.first = NULL;
	_inOperands.second = NULL;
	delete (_subroutine);
	_subroutine = NULL;
      }
    return (ret);
  }

  /*
  ** private methods
  */

  void	CPU::_push(void)	{ _subroutine = new Subroutine::Push(_arg); }
  void	CPU::_pop(void)		{ _subroutine = new Subroutine::Pop(); }
  void	CPU::_clear(void)	{ _subroutine = new Subroutine::Clear(); }
  void	CPU::_dup(void)		{ _subroutine = new Subroutine::Dup(); }
  void	CPU::_swap(void)	{ _subroutine = new Subroutine::Swap(); }
  void	CPU::_dump(void)	{ _subroutine = new Subroutine::Dump(); }
  void	CPU::_assert(void)	{ _subroutine = new Subroutine::Assert(_arg); }

  void	CPU::_add(void)
  { _subroutine = new Subroutine::Operation(Subroutine::Operation::OperationType::Add); }
  void	CPU::_sub(void)
  { _subroutine = new Subroutine::Operation(Subroutine::Operation::OperationType::Sub); }
  void	CPU::_mul(void)
  { _subroutine = new Subroutine::Operation(Subroutine::Operation::OperationType::Mul); }
  void	CPU::_div(void)
  { _subroutine = new Subroutine::Operation(Subroutine::Operation::OperationType::Div); }
  void	CPU::_mod(void)
  { _subroutine = new Subroutine::Operation(Subroutine::Operation::OperationType::Mod); }

  void	CPU::_load(void)	{ _subroutine = new Subroutine::Load(_arg, _registers); }
  void	CPU::_store(void)	{ _subroutine = new Subroutine::Store(_arg, _registers); }
  void	CPU::_print(void)	{ _subroutine = new Subroutine::Print(); }
  void	CPU::_exit(void)	{ _subroutine = new Subroutine::Exit(); }
}
