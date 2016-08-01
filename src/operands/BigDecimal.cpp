//
// BigDecimal.cpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Tue Jul 19 18:35:51 2016 Lum
// Last update Wed Jul 20 14:34:11 2016 Lum
//

#include "BigDecimal.hpp"

BigDecimal::BigDecimal(std::string const &_value) : AOperand(_value, INT8)
{
}

BigDecimal::BigDecimal(const BigDecimal &other) : AOperand(other)
{
}

BigDecimal::~BigDecimal()
{
}

IOperand	*BigDecimal::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
      IOperand	*ret = new BigDecimal(res);
      return ret;
  //   }
  // throw();
}

IOperand	*BigDecimal::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new BigDecimal(res);
  return ret;
  //   }
  // trow();
}

IOperand	*BigDecimal::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new BigDecimal(res);
  return ret;
  //   }
  // throw();
}


IOperand	*BigDecimal::operator/(const IOperand &rhs) const
{
  std::string	res(div(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new BigDecimal(res);
  return ret;
  //   }
  // throw();
}

IOperand	*BigDecimal::operator%(const IOperand &rhs) const
{
  std::string	res(div(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new BigDecimal(res);
  return ret;
  //   }
  // throw();
}
