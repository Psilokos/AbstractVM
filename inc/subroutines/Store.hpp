//
// Store.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:53:41 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 00:03:26 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef STORE_HPP_
# define STORE_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Store : public ASubroutine
  {
  public:
    Store(Component::CPU::Instruction::Argument const & arg, std::vector<IOperand *> & registers);
    Store(Store const &) = delete;
    virtual ~Store(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);

  private:
    Component::CPU::Instruction::Argument	_arg;
    std::vector<IOperand *> &			_registers;
  };
}

#endif /* !STORE_HPP_ */
