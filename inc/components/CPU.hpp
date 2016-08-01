//
// CPU.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 14:49:27 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 11:50:53 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef CPU_HPP_
# define CPU_HPP_

# include <list>
# include <map>
# include <vector>
# include "IComponent.hpp"
# include "IOperand.hpp"
# include "MMU.hpp"

namespace	Subroutine
{
  class		ASubroutine;
}

namespace	Component
{
  class		CPU : public IComponent
  {
  public:
    struct		Instruction
    {
    public:
      enum class	Opcode
      {
	Push,
	  Pop,
	  Clear,
	  Dup,
	  Swap,
	  Dump,
	  Assert,
	  Add,
	  Sub,
	  Mul,
	  Div,
	  Mod,
	  Load,
	  Store,
	  Print,
	  Exit
      };

      enum class	ArgType
      {
	None,
	  Operand,
	  Register
	  };


      struct		Argument
      {
      public:
	eOperandType	operandType;
	std::string	operandValue;
	unsigned	reg;
      };

      Opcode		opcode;
      Argument		arg;
    };

    typedef void	(CPU::*fctPtr)(void);
  public:
    CPU(void);
    CPU(CPU const &) = delete;
    virtual ~CPU(void);

    std::list<Communication> &	getCommunications(void);

    virtual IComponent &	operator<<(IComponent & nb);
    void			operator>>(std::list<Communication> & communications);
    std::string &		operator>>(std::string & outString);
    MMU::Instruction const * &	operator>>(MMU::Instruction const * & mmuInstr);

    bool			operator()(bool const exceptionRaised);

  private:
    std::vector<IOperand *>			_registers;
    std::map<Instruction::Opcode, fctPtr>	_instructions;
    std::pair<IOperand *, IOperand *>		_inOperands;
    std::list<Communication>			_communications;
    MMU::Instruction *				_mmuInstr;
    std::string					_outString;
    Subroutine::ASubroutine *			_subroutine;
    Instruction::Argument			_arg;

    void					_push(void);
    void					_pop(void);
    void					_clear(void);
    void					_dup(void);
    void					_swap(void);
    void					_dump(void);
    void					_assert(void);
    void					_add(void);
    void					_sub(void);
    void					_mul(void);
    void					_div(void);
    void					_mod(void);
    void					_load(void);
    void					_store(void);
    void					_print(void);
    void					_exit(void);
  };
}

# include "ASubroutine.hpp"

#endif /* !CPU_HPP_ */
