//
// Exit.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 18:06:36 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 23:02:42 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef EXIT_HPP_
# define EXIT_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Exit : public ASubroutine
  {
  public:
    Exit(void);
    Exit(Exit const &) = delete;
    virtual ~Exit(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };

  class		ExitException : public std::exception
  {
  public:
    ExitException(void) throw() {}
    virtual ~ExitException(void) throw() {}
  };
}

#endif /* !EXIT_HPP_ */
