//
// AOperand.hpp for abstractVM in /home/lumlum/tmp_abstractVM
//
// Made by Lum
// Login   <lumlum@epitech.net>
//
// Started on  Fri Jul 15 14:10:32 2016 Lum
// Last update Wed Jul 20 16:57:36 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef AOPERAND_HPP_
# define AOPERAND_HPP_

#include "IOperand.hpp"
#include "ToolBox.hpp"

class	AOperand : public IOperand
{
public:

  AOperand(std::string, eOperandType _type);
  AOperand(const AOperand &);
  ~AOperand();

  std::string	toString() const;
  eOperandType	getType() const;

  std::string		add(std::string const &op1, std::string const &op2) const;
  std::string		sub(std::string const &op1, std::string const &op2) const;
  std::string		mul_loop(std::string const &t1, std::string const &t2) const;
  std::string		mul(std::string const &op1, std::string const &op2) const;
  std::string		div(std::string const &op1, std::string const &op2) const;
  std::string		mod(std::string const &op2) const;
  int			compare(std::string const &op1, std::string const &op2) const;
  size_t		equalize(std::string  &op1, std::string &op2) const;

  virtual IOperand	*operator+(const IOperand &rhs) const = 0;
  virtual IOperand	*operator*(const IOperand &rhs) const = 0;
  virtual IOperand	*operator-(const IOperand &rhs) const = 0;
  virtual IOperand	*operator/(const IOperand &rhs) const = 0;
  virtual IOperand	*operator%(const IOperand &rhs) const = 0;
  virtual bool		operator!=(IOperand const & rhs) const;
  virtual bool		operator==(IOperand const & rhs) const;

protected :

  std::string		value;
  eOperandType		type;
  char			i_value;

  int			accuracy;
};

std::ostream& operator<<(std::ostream& os, const IOperand& op);

#endif /* !AOPERAND_HPP_ */
