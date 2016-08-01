//
// int8.hpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Fri Jul 15 10:17:30 2016 Lum
// Last update Tue Jul 19 18:29:17 2016 Lum
//

#ifndef	INT8_HPP_
# define INT8_HPP_

#include "AOperand.hpp"

class	Int8 : public AOperand
{
public:
  Int8(std::string const &_value);
  Int8(const Int8 &);
  ~Int8();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;

};

#endif /* !INT8_HPP_ */
