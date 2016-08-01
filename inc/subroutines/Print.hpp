//
// Print.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 17:59:05 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:13:57 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef PRINT_HPP_
# define PRINT_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Print : public ASubroutine
  {
  public:
    Print(void);
    Print(Print const &) = delete;
    virtual ~Print(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !PRINT_HPP_ */
