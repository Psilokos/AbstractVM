//
// MMU.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Sat Jul 16 13:09:49 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 18:12:42 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef MMU_HPP_
# define MMU_HPP_

# include <map>
# include <list>
# include <stdexcept>
# include "IComponent.hpp"
# include "IOperand.hpp"

namespace	Component
{
  class		MMU : public IComponent
  {
  public:
    class		Exception : public std::exception
    {
    public:
      Exception(void) throw () {}
      virtual ~Exception(void) throw() {}
    };

    struct		Instruction
    {
    public:
      enum class	Opcode
      {
	At,
	  Clear,
	  Pop,
	  Push,
	  Top
	  };

      struct		Argument
      {
	IOperand *	operand;
	unsigned	idx;
      };

      Opcode		opcode;
      Argument		arg;
    };

    typedef void	(MMU::*fctPtr)(Instruction::Argument const &);

  public:
    MMU(void);
    MMU(MMU const &) = delete;
    virtual ~MMU(void);

    virtual IComponent &	operator<<(IComponent & nb);
    void			operator>>(IOperand * & outOperand);

  private:
    std::list<IOperand *>			_memory;
    std::map<Instruction::Opcode, fctPtr>	_instructions;
    IOperand *					_outOperand;

    void					_at(Instruction::Argument const & arg);
    void					_clear(Instruction::Argument const & arg);
    void					_pop(Instruction::Argument const & arg);
    void					_push(Instruction::Argument const & arg);
    void					_top(Instruction::Argument const & arg);
  };
}

#endif /* !MMU_HPP_ */
