//
// Dump.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 13:00:20 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:12:43 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef DUMP_HPP_
# define DUMP_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Dump : public ASubroutine
  {
  public:
    Dump(void);
    Dump(Dump const &) = delete;
    virtual ~Dump(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !DUMP_HPP_ */
