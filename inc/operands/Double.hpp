//
// Double.hpp for Double in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 12:01:07 2016 Lum
// Last update Tue Jul 19 18:31:05 2016 Lum
//

#ifndef	DOUBLE_HPP_
# define DOUBLE_HPP_

#include "AOperand.hpp"

class	Double : public AOperand
{
public:
  Double(std::string const &_value);
  Double(const Double &);
  ~Double();

  IOperand	*operator+(const IOperand &rhs) const;
  IOperand	*operator*(const IOperand &rhs) const;
  IOperand	*operator-(const IOperand &rhs) const;
  IOperand	*operator/(const IOperand &rhs) const;
  IOperand	*operator%(const IOperand &rhs) const;
};

#endif /* !DOUBLE_HPP_ */
