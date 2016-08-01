//
// Int16.hpp for Int16 in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 11:55:31 2016 Lum
// Last update Tue Jul 19 18:30:02 2016 Lum
//

#ifndef	INT16_HPP_
# define INT16_HPP_

#include "AOperand.hpp"

class	Int16 : public AOperand
{
public:
  Int16(std::string const &_value);
  Int16(const Int16 &);
  ~Int16();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;

};

#endif /* !INT16_HPP_ */
