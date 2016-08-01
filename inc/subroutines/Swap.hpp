//
// Swap.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 12:48:54 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:13:40 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef SWAP_HPP_
# define SWAP_HPP_

# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Swap : public ASubroutine
  {
  public:
    Swap(void);
    Swap(Swap const &) = delete;
    virtual ~Swap(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);
  };
}

#endif /* !SWAP_HPP_ */
