//
// IOpenrand.hpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Fri Jul 15 10:10:58 2016 Lum
// Last update Wed Jul 20 16:56:20 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

#include <iostream>
#include <sstream>
#include <string>

enum	eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
  };

class	IOperand
{
public:

  virtual ~IOperand() {}

  virtual std::string	toString() const = 0;
  virtual eOperandType	getType() const = 0;

  virtual IOperand	*operator+(const IOperand &rhs) const = 0;
  virtual IOperand	*operator*(const IOperand &rhs) const = 0;
  virtual IOperand	*operator-(const IOperand &rhs) const = 0;
  virtual IOperand	*operator/(const IOperand &rhs) const = 0;
  virtual IOperand	*operator%(const IOperand &rhs) const = 0;
  virtual bool		operator!=(IOperand const & rhs) const = 0;
  virtual bool		operator==(IOperand const & rhs) const = 0;
};

std::ostream& operator<<(std::ostream& os, const IOperand& op);

#endif /* !IOPERAND_HPP_ */
