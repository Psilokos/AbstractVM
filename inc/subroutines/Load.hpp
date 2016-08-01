//
// Load.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:00:03 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:25:05 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef LOAD_HPP_
# define LOAD_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Load : public ASubroutine
  {
  public:
    Load(Component::CPU::Instruction::Argument const & arg, std::vector<IOperand *> & registers);
    Load(Load const &) = delete;
    virtual ~Load(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);

  private:
    Component::CPU::Instruction::Argument	_arg;
    std::vector<IOperand *> &			_registers;
  };
}

#endif /* !LOAD_HPP_ */
