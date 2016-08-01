//
// Int32.hpp for Int32 in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 11:56:25 2016 Lum
// Last update Tue Jul 19 18:30:37 2016 Lum
//

#ifndef	INT32_HPP_
# define INT32_HPP_

#include "AOperand.hpp"

class	Int32 : public AOperand
{
public:
  Int32(std::string const &_value);
  Int32(const Int32 &);
  ~Int32();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;

};

#endif /* !INT32_HPP_ */
