//
// Assert.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 13:40:18 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:08:48 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef ASSERT_HPP_
# define ASSERT_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Assert : public ASubroutine
  {
  public:
    Assert(Component::CPU::Instruction::Argument const & arg);
    Assert(Assert const &) = delete;
    virtual ~Assert(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  private:
    Component::CPU::Instruction::Argument const		_arg;
  };
}

#endif /* !ASSERT_HPP_ */
