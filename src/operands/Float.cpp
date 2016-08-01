//
// Float.cpp for Float in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 12:03:31 2016 Lum
// Last update Wed Jul 20 15:51:20 2016 Lum
//

#include "Float.hpp"

Float::Float(std::string const &_value) : AOperand(_value, INT8)
{
}

Float::Float(const Float &other) : AOperand(other)
{
}

Float::~Float()
{
}

IOperand	*Float::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
      IOperand	*ret = new Float(res);
      return ret;
  //   }
  // throw();
}

IOperand	*Float::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Float(res);
  return ret;
  //   }
  // trow();
}

IOperand	*Float::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Float(res);
  return ret;
  //   }
  // throw();
}

IOperand	*Float::operator/(const IOperand &rhs) const
{
  double	t1 = std::stol(value);
  double	t2 = std::stol(rhs.toString());
  double	res;
  std::stringstream	ss;

  if (t2 == 0)
    throw ToolBox::Exception("Float : Divide by 0");
  res = t1 / t2;
  if (res < -128)
    throw ToolBox::Exception("Float : Underflow");
  else if (res > 127)
  throw ToolBox::Exception("Float : Overflow");

  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Float(str);
  return ret;
}

IOperand	*Float::operator%(const IOperand &rhs) const
{
  std::string	res(div(value, rhs.toString()));
  // if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
  //   {
  IOperand	*ret = new Float(res);
  return ret;
  //   }
  // throw();
}
