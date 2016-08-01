//
// ISubroutine.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Mon Jul 18 11:52:41 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:05:24 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef ASUBROUTINE_HPP_
# define ASUBROUTINE_HPP_

# include <utility>
# include "CPU.hpp"
# include "MMU.hpp"

namespace	Subroutine
{
  class	ASubroutine
  {
  public:
    ASubroutine(void);
    ASubroutine(ASubroutine const &) = delete;
    virtual ~ASubroutine(void);

    std::list<Component::Communication>	getCommunications(void);
    Component::MMU::Instruction *	getMMUInstruction(void);
    std::string				getOutString(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised) = 0;

  protected:
    unsigned					_callNb;
    std::list<Component::Communication>		_communications;
    Component::MMU::Instruction *		_mmuInstr;
    std::string					_outString;
  };
}

#endif /* !ASUBROUTINE_HPP_ */
