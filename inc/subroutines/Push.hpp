//
// Push.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:00:58 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:14:15 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef PUSH_HPP_
# define PUSH_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Push : public ASubroutine
  {
  public:
    Push(Component::CPU::Instruction::Argument const & arg);
    Push(Push const &) = delete;
    virtual ~Push(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);

  private:
    Component::CPU::Instruction::Argument const		_arg;
  };
}

#endif /* !PUSH_HPP_ */
