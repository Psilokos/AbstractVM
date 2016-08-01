//
// Chipset.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 19:52:19 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 18:02:50 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef CHIPSET_HPP_
# define CHIPSET_HPP_

# include <map>
# include <string>
# include "CPU.hpp"
# include "MMU.hpp"

namespace	Component
{
  namespace	Chipset
  {
    class		NorthBridge;

    class		SouthBridge : public IComponent
    {
    public:
      SouthBridge(void);
      SouthBridge(SouthBridge const &) = delete;
      ~SouthBridge(void);

      SouthBridge &		operator<<(std::list<std::string> const & words);
      virtual IComponent &	operator<<(IComponent & nb);
      void			operator>>(CPU::Instruction const * & instr);
      std::string &		operator>>(std::string & s);

    private:
      typedef void	(SouthBridge::*fctPtr)(std::string const & arg);

      std::map<std::string, CPU::Instruction::Opcode>			_opcodes;
      std::map<CPU::Instruction::Opcode, CPU::Instruction::ArgType>	_argTypes;
      std::map<CPU::Instruction::ArgType, fctPtr>			_fmtArg;
      std::map<std::string, eOperandType>				_operandTypes;
      CPU::Instruction *						_cpuInstr;
      std::string							_outString;

      void				_getOperand(std::string const & arg);
      void				_getRegister(std::string const & arg);
    };

    class		NorthBridge : public IComponent
    {
    public:
      NorthBridge(void);
      NorthBridge(NorthBridge const &) = delete;
      ~NorthBridge(void);

      virtual IComponent &	operator<<(IComponent & component);
      void			operator>>(CPU::Instruction const * & cpuInstr);
      void			operator>>(MMU::Instruction const * & mmuInstr);
      void			operator>>(IOperand * & operand);
      void			operator>>(std::string & outString);

    private:
      CPU::Instruction const *	_cpuInstr;
      MMU::Instruction const *	_mmuInstr;
      IOperand *		_operand;
      std::string		_outString;
    };
  }
}

#endif /* !CHIPSET_HPP_ */
