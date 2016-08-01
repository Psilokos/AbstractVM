//
// BigDecimal.hpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Tue Jul 19 18:34:46 2016 Lum
// Last update Tue Jul 19 18:35:28 2016 Lum
//

#ifndef	BIGDECIMAL_HPP_
# define BIGDECIMAL_HPP_

#include "AOperand.hpp"

class	BigDecimal : public AOperand
{
public:
  BigDecimal(std::string const &_value);
  BigDecimal(const BigDecimal &);
  ~BigDecimal();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;

};

#endif /* !BIGDECIMAL_HPP_ */
