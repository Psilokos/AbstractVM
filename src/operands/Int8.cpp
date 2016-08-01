//
// Int8.cpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Fri Jul 15 10:35:17 2016 Lum
// Last update Wed Jul 20 15:46:45 2016 Lum
//

#include "Int8.hpp"

Int8::Int8(std::string const &_value) : AOperand(_value, INT8)
{
}

Int8::Int8(const Int8 &other) : AOperand(other)
{
}

Int8::~Int8()
{
}

IOperand	*Int8::operator+(const IOperand &rhs) const
{
  std::string	res(add(value, rhs.toString()));
  // if (compare(res, "127") == 1)
  //   throw ToolBox::Exception("Int8 : Overflow");
  if (std::stoi(res) >= -128 && std::stoi(res) <= 127)
    {
      IOperand	*ret = new Int8(res);
      return ret;
    }
  return NULL;
}

IOperand	*Int8::operator*(const IOperand &rhs) const
{
  std::string	res(mul_loop(value, rhs.toString()));
  // if (compare(res, "127") == 1)
  //   throw ToolBox::Exception("Int8 : Overflow");
  IOperand	*ret = new Int8(res);
  return ret;
}

IOperand	*Int8::operator-(const IOperand &rhs) const
{
  std::string	res(sub(value, rhs.toString()));
  if (compare(res, "127") == 1)
    throw ToolBox::Exception("Int8 : Overflow");
  IOperand	*ret = new Int8(res);
  return ret;
}

IOperand	*Int8::operator/(const IOperand &rhs) const
{
  long int	t1 = std::stol(value);
  long int	t2 = std::stol(rhs.toString());
  long int	res;
  std::stringstream	ss;

  if (t2 == 0)
    throw ToolBox::Exception("Int8 : Divide by 0");
  res = t1 / t2;
  if (res < -128)
    throw ToolBox::Exception("Int8 : Underflow");
  else if (res > 127)
    throw ToolBox::Exception("Int8 : Overflow");
  ss << res;
  std::string str = ss.str();
  IOperand	*ret = new Int8(str);
  return ret;
}

IOperand	*Int8::operator%(const IOperand &rhs) const
{
  long int	t1 = std::stol(value);
  long int	t2 = std::stol(rhs.toString());
  long int	res;
  std::stringstream	ss;

  if (t2 == 0)
    throw ToolBox::Exception("Int8 : Divide by 0");
  res = t1 % t2;
  if (res < -128)
    throw ToolBox::Exception("Int8 : Underflow");
  else if (res > 127)
    throw ToolBox::Exception("Int8 : Overflow");
  std::cout << "res = " << res << std::endl;
  ss << res;
  std::string str = ss.str();
  std::cout << "str = " << str << std::endl;
  IOperand	*ret = new Int8(str);
  return ret;
}

std::ostream& operator<<(std::ostream& os, const IOperand& op)
{
  os << op.toString();
  return os;
}
