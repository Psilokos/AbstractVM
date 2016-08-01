//
// Float.hpp for Float in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 12:02:26 2016 Lum
// Last update Tue Jul 19 18:31:35 2016 Lum
//

#ifndef	FLOAT_HPP_
# define FLOAT_HPP_

#include "AOperand.hpp"

class	Float : public AOperand
{
public:
  Float(std::string const &_value);
  Float(const Float &);
  ~Float();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;

};

#endif /* !FLOAT_HPP_ */
