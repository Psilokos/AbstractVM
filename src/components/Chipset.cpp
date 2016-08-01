//
// Chipset.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 12:25:12 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 15:31:35 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Chipset.hpp"
#include "Parse.hpp"

namespace	Component
{
  namespace	Chipset
  {
    SouthBridge::SouthBridge(void) : _cpuInstr(NULL)
    {
      _opcodes["push"] = CPU::Instruction::Opcode::Push;
      _opcodes["pop"] = CPU::Instruction::Opcode::Pop;
      _opcodes["clear"] = CPU::Instruction::Opcode::Clear;
      _opcodes["dup"] = CPU::Instruction::Opcode::Dup;
      _opcodes["swap"] = CPU::Instruction::Opcode::Swap;
      _opcodes["dump"] = CPU::Instruction::Opcode::Dump;
      _opcodes["assert"] = CPU::Instruction::Opcode::Assert;
      _opcodes["add"] = CPU::Instruction::Opcode::Add;
      _opcodes["sub"] = CPU::Instruction::Opcode::Sub;
      _opcodes["mul"] = CPU::Instruction::Opcode::Mul;
      _opcodes["div"] = CPU::Instruction::Opcode::Div;
      _opcodes["mod"] = CPU::Instruction::Opcode::Mod;
      _opcodes["load"] = CPU::Instruction::Opcode::Load;
      _opcodes["store"] = CPU::Instruction::Opcode::Store;
      _opcodes["print"] = CPU::Instruction::Opcode::Print;
      _opcodes["exit"] = CPU::Instruction::Opcode::Exit;

      _argTypes[CPU::Instruction::Opcode::Push] = CPU::Instruction::ArgType::Operand;
      _argTypes[CPU::Instruction::Opcode::Pop] = CPU::Instruction::ArgType::Operand;
      _argTypes[CPU::Instruction::Opcode::Clear] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Dup] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Swap] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Dump] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Assert] = CPU::Instruction::ArgType::Operand;
      _argTypes[CPU::Instruction::Opcode::Add] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Sub] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Mul] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Div] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Mod] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Load] = CPU::Instruction::ArgType::Register;
      _argTypes[CPU::Instruction::Opcode::Store] = CPU::Instruction::ArgType::Register;
      _argTypes[CPU::Instruction::Opcode::Print] = CPU::Instruction::ArgType::None;
      _argTypes[CPU::Instruction::Opcode::Exit] = CPU::Instruction::ArgType::None;

      _fmtArg[CPU::Instruction::ArgType::Operand] = &SouthBridge::_getOperand;
      _fmtArg[CPU::Instruction::ArgType::Register] = &SouthBridge::_getRegister;

      _operandTypes["int8"] = eOperandType::INT8;
      _operandTypes["int16"] = eOperandType::INT16;
      _operandTypes["int32"] = eOperandType::INT32;
      _operandTypes["float"] = eOperandType::FLOAT;
      _operandTypes["double"] = eOperandType::DOUBLE;
      _operandTypes["bigdecimal"] = eOperandType::BIGDECIMAL;
    }

    SouthBridge::~SouthBridge(void)
    {
      if (_cpuInstr)
	delete (_cpuInstr);
    }

    IComponent &
    SouthBridge::operator<<(IComponent & component)
    {
      Parse *		parser = dynamic_cast<Parse *>(&component);
      NorthBridge *	nb = dynamic_cast<NorthBridge *>(&component);

      if (parser)
	{
	  std::list<std::string>	words;

	  *parser >> words;
	  if (!words.size())
	    throw ToolBox::Exception("the program does not have an exit instruction");
	  _cpuInstr = new CPU::Instruction();
	  _cpuInstr->opcode = _opcodes[words.front()];
	  if (_fmtArg[_argTypes[_cpuInstr->opcode]])
	    (this->*_fmtArg[_argTypes[_cpuInstr->opcode]])(words.back());
	}
      else if (nb)
	*nb >> _outString;
      return (*this);
    }

    void
    SouthBridge::operator>>(CPU::Instruction const * & cpuInstr)
    {
      cpuInstr = _cpuInstr;
      _cpuInstr = NULL;
    }

    std::string &
    SouthBridge::operator>>(std::string & outString)
    {
      outString = _outString;
      _outString.clear();
      return (outString);
    }

    NorthBridge::NorthBridge(void) : _cpuInstr(NULL), _mmuInstr(NULL), _operand(NULL) {}

    NorthBridge::~NorthBridge(void)
    {
      if (_cpuInstr)
	delete (_cpuInstr);
      if (_mmuInstr)
	{
	  if (_mmuInstr->arg.operand)
	    delete (_mmuInstr->arg.operand);
	  delete (_mmuInstr);
	}
      if (_operand)
	delete (_operand);
    }

    IComponent &
    NorthBridge::operator<<(IComponent & component)
    {
      CPU *			cpu = dynamic_cast<CPU *>(&component);
      MMU *			mmu = dynamic_cast<MMU *>(&component);
      SouthBridge *		sb = dynamic_cast<SouthBridge *>(&component);
      MMU::Instruction const *	mmuInstr;
      std::string		outString;

      if (cpu)
	{
	  if (*cpu >> mmuInstr)
	    _mmuInstr = mmuInstr;
	  if ((*cpu >> outString).length())
	    _outString = outString;
	}
      else if (mmu)
	*mmu >> _operand;
      else if (sb)
	*sb >> _cpuInstr;
      return (*this);
    }

    void
    NorthBridge::operator>>(CPU::Instruction const * & cpuInstr)
    {
      cpuInstr = _cpuInstr;
      _cpuInstr = NULL;
    }

    void
    NorthBridge::operator>>(MMU::Instruction const * & mmuInstr)
    {
      mmuInstr = _mmuInstr;
      _mmuInstr = NULL;
    }

    void
    NorthBridge::operator>>(IOperand * & operand)
    {
      operand = _operand;
      _operand = NULL;
    }

    void
    NorthBridge::operator>>(std::string & outString)
    {
      outString = _outString;
      _outString.clear();
    }

    /*
    ** private methods
    */

    void
    SouthBridge::_getOperand(std::string const & arg)
    {
      auto	argParts = ToolBox::tokenize(arg, "()");

      _cpuInstr->arg.operandType = _operandTypes[argParts.front()];
      _cpuInstr->arg.operandValue = argParts.back();
    }

    void
    SouthBridge::_getRegister(std::string const & arg)
    {
      auto	argParts = ToolBox::tokenize(arg, "()");

      _cpuInstr->arg.reg = stoi(argParts.back());
    }
  }
}
