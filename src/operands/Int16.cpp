//
// Int16.cpp for Int16 in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 11:54:15 2016 Lum
// Last update Wed Jul 20 15:48:11 2016 Lum
//

#include "Int16.hpp"

Int16::Int16(std::string const &_value) : AOperand(_value, INT8)
{
}

Int16::Int16(const Int16 &other) : AOperand(other)
{
}

Int16::~Int16()
{
}

IOperand	*Int16::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (compare(res, "32767") == 1)
  //   throw ToolBox::Exception("Int16 : Overflow");
  IOperand	*ret = new Int16(res);
  return ret;
}

IOperand	*Int16::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (compare(res, "32767") == 1)
  //   throw ToolBox::Exception("Int16 : Overflow");
  IOperand	*ret = new Int16(res);
  return ret;
}

IOperand	*Int16::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  // if (compare(res, "32767") == 1)
  //   throw ToolBox::Exception("Int16 : Overflow");
  IOperand	*ret = new Int16(res);
  return ret;
}

IOperand	*Int16::operator/(const IOperand &rhs) const
{
  long int	t1 = std::stol(value);
  long int	t2 = std::stol(rhs.toString());
  long int	res;
  std::stringstream	ss;

  if (t2 == 0 )
    throw ToolBox::Exception("Int16 : Divide by 0");
  res = t1 / t2;
  if (res < -32768)
    throw ToolBox::Exception("Int16 : Underflow");
  else if (res > 32767)
    throw ToolBox::Exception("Int16 : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Int16(str);
  return ret;
}

IOperand	*Int16::operator%(const IOperand &rhs) const
{
  long int	t1 = std::stol(value);
  long int	t2 = std::stol(rhs.toString());
  long int	res;
  std::stringstream	ss;

  if (t2 == 0)
    throw ToolBox::Exception("Int16 : Divide by 0");
  res = t1 % t2;
  if (res < -32768)
    throw ToolBox::Exception("Int16 : Underflow");
  else if (res > 32767)
    throw ToolBox::Exception("Int16 : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Int16(str);
  return ret;
}
