//
// Double.cpp for Double in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 12:00:36 2016 Lum
// Last update Wed Jul 20 14:34:23 2016 Lum
//

#include <cmath>
#include <ctgmath>
#include "Double.hpp"

Double::Double(std::string const &_value) : AOperand(_value, INT8)
{
}

Double::Double(const Double &other) : AOperand(other)
{
}

Double::~Double()
{
}

IOperand	*Double::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
      IOperand	*ret = new Double(res);
      return ret;
  //   }
  // throw();
}

IOperand	*Double::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Double(res);
  return ret;
  //   }
  // throw();
}

IOperand	*Double::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Double(res);
  return ret;
  //   }
  // throw();
}

IOperand	*Double::operator/(const IOperand &rhs) const
{
  long double	t1 = std::stol(value);
  long double	t2 = std::stol(rhs.toString());
  long double	res;
  std::stringstream	ss;

  if (t2 == 0 )
    throw ToolBox::Exception("Int16 : Divide by 0");
  res = t1 / t2;
  if (res < -128)
    throw ToolBox::Exception("Double : Underflow");
  else if (res > 127)
  throw ToolBox::Exception("Double : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Double(str);
  return ret;
}

IOperand	*Double::operator%(const IOperand &rhs) const
{
  std::string	res(div(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Double(res);
  return ret;
  //   }
  // throw();
}
