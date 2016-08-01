//
// Dup.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:39:11 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:12:50 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef DUP_HPP_
# define DUP_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Dup : public ASubroutine
  {
  public:
    Dup(void);
    Dup(Dup const &) = delete;
    virtual ~Dup(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !DUP_HPP_ */
