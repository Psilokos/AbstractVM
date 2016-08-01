//
// Int32.cpp for Int32 in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Sun Jul 17 11:57:18 2016 Lum
// Last update Wed Jul 20 15:50:55 2016 Lum
//

#include "Int32.hpp"

Int32::Int32(std::string const &_value) : AOperand(_value, INT8)
{
}

Int32::Int32(const Int32 &other) : AOperand(other)
{
}

Int32::~Int32()
{
}

IOperand	*Int32::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (compare(res, "2147483647") == 1)
  //   throw ToolBox::Exception("Int32 : Overflow");
  IOperand	*ret = new Int32(res);
  return ret;
}

IOperand	*Int32::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (compare(res, "2147483647") == 1)
  //   throw ToolBox::Exception("Int32 : Overflow");
  IOperand	*ret = new Int32(res);
  return ret;
}

IOperand	*Int32::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  // if (compare(res, "2147483648") == 1)
  //   throw ToolBox::Exception("Int32 : Overflow");
  IOperand	*ret = new Int32(res);
  return ret;
}

IOperand		*Int32::operator/(const IOperand &rhs) const
{
  long int		t1 = std::stol(value);
  long int		t2 = std::stol(rhs.toString());
  long int		res;
  std::stringstream	ss;

  if (t2 == 0 )
    throw ToolBox::Exception("Int32 : Divide by 0");
  res = t1 / t2;
  if (res < -2147483648)
    throw ToolBox::Exception("Int32 : Underflow");
  else if (res > 2147483647)
    throw ToolBox::Exception("Int32 : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Int32(str);
  return ret;
}

IOperand		*Int32::operator%(const IOperand &rhs) const
{
  long int		t1 = std::stol(value);
  long int		t2 = std::stol(rhs.toString());
  long int		res;
  std::stringstream	ss;

  if (t2 == 0)
    throw ToolBox::Exception("Int16 : Divide by 0");
  res = t1 % t2;
  if (res < -2147483648)
    throw ToolBox::Exception("Int32 : Underflow");
  else if (res > 2147483647)
    throw ToolBox::Exception("Int32 : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Int32(str);
  return ret;
}
