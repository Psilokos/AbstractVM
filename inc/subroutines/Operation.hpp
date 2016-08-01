//
// Operation.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Tue Jul 19 18:46:03 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:13:05 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef OPERATION_HPP_
# define OPERATION_HPP_

# include <map>
# include "ASubroutine.hpp"

namespace	Subroutine
{
  class		Operation : public ASubroutine
  {
  public:
    enum class	OperationType
    {
      Add,
	Sub,
	Mul,
	Div,
	Mod
	};

    Operation(OperationType const & opType);
    Operation(Operation const &) = delete;
    virtual ~Operation(void);

    virtual bool	operator()(std::pair<IOperand *, IOperand *> & inOperands,
				   bool const exceptionRaised);

  private:
    typedef IOperand *	(Operation::*fctPtr)(IOperand const &, IOperand const &);

    std::map<OperationType, fctPtr>	_operations;
    OperationType			_opType;

    IOperand *				_add(IOperand const & a, IOperand const & b);
    IOperand *				_sub(IOperand const & a, IOperand const & b);
    IOperand *				_mul(IOperand const & a, IOperand const & b);
    IOperand *				_div(IOperand const & a, IOperand const & b);
    IOperand *				_mod(IOperand const & a, IOperand const & b);
  };
}

#endif /* !OPERATION_HPP_ */
