//
// Pop.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:33:02 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:13:11 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef POP_HPP_
# define POP_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Pop : public ASubroutine
  {
  public:
    Pop(void);
    Pop(Pop const &) = delete;
    virtual ~Pop(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !POP_HPP_ */
