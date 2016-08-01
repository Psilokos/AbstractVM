//
// AOperand.cpp for AOperand.cpp in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Fri Jul 15 14:12:53 2016 Lum
// Last update Wed Jul 20 17:10:29 2016 Victorien LE COUVIOUR--TUFFET
//

#include "AOperand.hpp"

AOperand::AOperand(std::string _value, eOperandType _type) : value(_value), type(_type)
{
}

AOperand::AOperand(const AOperand &other)
{
  value = other.value;
  type = other.type;
}

AOperand::~AOperand()
{
}

std::string	AOperand::toString() const
{
  return value;
}

eOperandType	AOperand::getType() const
{
  return type;
}


size_t		AOperand::equalize(std::string &op1, std::string &op2) const
{
  size_t	pos = op1.find_last_of(".");
  size_t	pos2 = op2.find_last_of(".");
  std::string	tmp1 = "";
  std::string	tmp2 = "";

  if (pos != std::string::npos)
    {
      tmp1 += op1.substr(pos + 1);
      op1.erase(pos);
    }
  if (pos2 != std::string::npos)
    {
      tmp2 += op2.substr(pos2 + 1);
      op2.erase(pos2);
    }
  while (op1.size() != op2.size())
    {
      if (op1.size() < op2.size())
	op1.insert(0, "0");
      else if (op2.size() < op1.size())
	op2.insert(0, "0");
    }
  while (tmp1.size() != tmp2.size())
    {
      if (tmp1.size() < tmp2.size())
	tmp1 += "0";
      else if (tmp2.size() < tmp1.size())
	tmp2 += "0";
    }
  op1 += "." + tmp1;
  op2 += "." + tmp2;
  if (op1.find_last_of(".") == op1.size() - 1)
    op1.erase(op1.size() - 1);
  if (op2.find_last_of(".") == op2.size() - 1)
    op2.erase(op2.size() - 1);
  pos = op1.find_last_of(".");
  pos2 = op2.find_last_of(".");
  if(pos != std::string::npos && pos2 != std::string::npos)
    return (op1.size() - 1 - pos) + (op2.size() - 1 - pos2);
  else if (pos != std::string::npos || pos2 != std::string::npos)
    return pos > pos2 ? (op2.size() - 1 - pos2) : (op1.size() - 1 - pos);
  return pos;
}

std::string	AOperand::add(std::string const &op1, std::string const &op2) const
{
  std::string	t1 = op1;
  std::string	t2 = op2;
  int		rest = 0;
  std::string	res = "";
  std::string		val;
  std::string::reverse_iterator	it;

  equalize(t1, t2);
  std::string::reverse_iterator	it2 = t2.rbegin();
  for(it = t1.rbegin(); it != t1.rend(); it++, it2++)
    {
      if (*it == '.')
	{
	  res.insert(0, ".");
	  it++;
	  it2++;
	}
      val = (((*it - '0') + (*it2 - '0') + rest) % 10) + '0';
      res.insert(0, val);
      rest = (((*it - '0') + (*it2 - '0') + rest)) / 10;
    }
  if (rest != 0)
    {
      val = rest + '0';
      res.insert(0, val);
    }
  if (res.find_last_of(".") == res.size() - 1)
    res.erase(res.size() - 1);
  return res;
}

std::string	AOperand::sub(std::string const &op1, std::string const &op2) const
{
  std::string	t1 = op1;
  std::string	t2 = op2;
  int		rest = 0;
  std::string	res = "";
  std::string		val;
  std::string::reverse_iterator	it;
  equalize(t1, t2);
  std::string::reverse_iterator	it2 = t2.rbegin();
  for(it = t1.rbegin(); it != t1.rend(); it++, it2++)
    {
      if (*it == '.')
	{
	  res.insert(0, ".");
	  it++;
	  it2++;
	}
      if (*it < *it2 + rest)
	*it += 10;
      val = ((*it - '0') - ((*it2 + rest) - '0')) + '0';
      res.insert(0, val);
      rest = 0;
      if (*it > '9')
	rest = 1;
    }
  res.erase(0, res.find_first_not_of("0"));
  return res;
}

std::string	AOperand::mul_loop(std::string const &t1, std::string const &t2) const
{
  std::string	op2 = t2;
  std::string	op1 = t1;
  size_t	pos;
  // size_t	accuracy = (t1.find_last_of(".") != std::string::npos) ?
  //   (t1.size() - t1.find_last_of(".")) : 0;
  std::string	res2;
  int		stat = 0;
  int		i = 0;
  std::string	res1;

  // accuracy = (op2.size() - op2.find_last_of("."));
  pos = equalize(op1, op2);
  if (compare(op1, op2) == 1)
    op1.swap(op2);
  op2.erase(0, op2.find_first_not_of("0"));
  if(op2[0] == '.')
    op2.insert(0, "0");
  res1 = mul(op1, op2);
  while (op2.size() > 1)
    {
      op2.erase(op2.size() - 1);
      if(op2[op2.size() - 1] == '.')
	op2.erase(op2.size() - 1);
      res2 = mul(op1, op2);
      while (i++ < stat + 1)
	res2 += "0";
      res1 = add(res1, res2);
      i = 0;
      stat++;
    }
  // res1.erase(0, res1.find_first_not_of("0"));
  if (pos != std::string::npos)
    res1.insert((res1.size() - pos) , ".");
  // res1.erase(res1.find_first_of(".") + accuracy);
  return res1;
}


std::string	AOperand::mul(std::string const &op1, std::string const &op2) const
{
  std::string	t1 = op1;
  std::string	t2 = op2;
  std::string	res = "";
  std::string	val1;
  std::string	val2 = "0";
  std::string::reverse_iterator	it;
  char		c = op2[op2.size() - 1];
  int		rest = 0;

  equalize(t1, t2);
  for(it = t1.rbegin(); it != t1.rend(); it++)
    {
      if (*it == '.')
	{
	  it++;
	}
      val1 = (((*it - '0') * (c - '0') + rest) % 10) + '0';
      res.insert(0, val1);
      rest = (((*it - '0') * (c - '0') + rest)) / 10;
    }
  if (rest != 0)
    {
      val1 = rest + '0';
      res.insert(0, val1);
    }
  return res;
}

std::string	AOperand::div(std::string const &op1, std::string const &op2) const
{
  std::string	j = "1";
  std::string	t2 = op2;

  while (compare(op1,t2) == 0)
    {
      t2 = mul_loop(op2, j);
      if (compare(op1, t2) == 0)
	j = add("1", j);
    }
  if (compare(op1, t2) == -1)
    return j;
  if (compare(op1, t2) == 1 && j == "1")
    return "0";
  return sub(j, "1");
}

int	AOperand::compare(std::string const &op1, std::string const &op2) const
{
  size_t	i = 0;
  std::string	t1 = op1;
  std::string	t2 = op2;

  equalize(t1, t2);
  while (t1[i] - t2[i] == 0 && i < t1.size())
    i++;
  if (i == t1.size() || i == t2.size())
    return -1;
  return (t1[i] - t2[i]) > 0 ? 0 : 1;
}

std::string	AOperand::mod(std::string const &op2) const
{
  return op2;
}

bool		AOperand::operator!=(const IOperand &rhs) const
{
  return (!(*this == rhs));
}

bool		AOperand::operator==(const IOperand &rhs) const
{
  auto		o1 = this->toString();
  auto		o2 = rhs.toString();

  equalize(o1, o2);
  return (o1 == o2);
}
