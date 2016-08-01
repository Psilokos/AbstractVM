//
// MMU.cpp for  in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Sat Jul 16 13:09:57 2016 Victorien LE COUVIOUR--TUFFET
// Last update Thu Jul 21 00:14:19 2016 Victorien LE COUVIOUR--TUFFET
//

#include <iterator>
#include "Chipset.hpp"
#include "MMU.hpp"

namespace	Component
{
  MMU::MMU(void) : _outOperand(NULL)
  {
    _instructions[MMU::Instruction::Opcode::At] = &MMU::_at;
    _instructions[MMU::Instruction::Opcode::Clear] = &MMU::_clear;
    _instructions[MMU::Instruction::Opcode::Pop] = &MMU::_pop;
    _instructions[MMU::Instruction::Opcode::Push] = &MMU::_push;
    _instructions[MMU::Instruction::Opcode::Top] = &MMU::_top;
  }

  MMU::~MMU(void)
  {
    for (auto &operand : _memory)
      delete (operand);
  }

  IComponent &
  MMU::operator<<(IComponent & nb)
  {
    MMU::Instruction const *	instr;

    dynamic_cast<Component::Chipset::NorthBridge &>(nb) >> instr;
    (this->*_instructions[instr->opcode])(instr->arg);
    delete (instr);
    return (*this);
  }

  void
  MMU::operator>>(IOperand * & outOperand)
  {
    outOperand = _outOperand;
    _outOperand = NULL;
  }

  /*
  ** private methods
  */

  void
  MMU::_at(MMU::Instruction::Argument const & arg)
  {
    auto	it = _memory.begin();

    if (arg.idx >= _memory.size())
      throw MMU::Exception();
    std::advance(it, arg.idx);
    _outOperand = *it;
  }

  void	MMU::_clear(MMU::Instruction::Argument const &)
  {
    for (auto it = _memory.begin(); it != _memory.end(); it = _memory.erase(it))
      delete (*it);
  }

  void
  MMU::_pop(MMU::Instruction::Argument const &)
  {
    if (!_memory.size())
      throw MMU::Exception();
    _memory.pop_front();
  }

  void
  MMU::_push(MMU::Instruction::Argument const & arg)
  {
    if (_memory.size() == _memory.max_size())
      throw MMU::Exception();
    _memory.push_back(arg.operand);
  }

  void
  MMU::_top(MMU::Instruction::Argument const &)
  {
    if (!_memory.size())
      throw MMU::Exception();
    _outOperand = _memory.front();
  }
}
