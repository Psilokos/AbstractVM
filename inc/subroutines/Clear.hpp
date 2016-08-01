//
// Clear.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:36:29 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:12:36 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef CLEAR_HPP_
# define CLEAR_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Clear : public ASubroutine
  {
  public:
    Clear(void);
    Clear(Clear const &) = delete;
    virtual ~Clear(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !CLEAR_HPP_ */
