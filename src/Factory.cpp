//
// Factory.cpp for abstractVM in
//
// Made by Stéphane lejeune
// Login   <thepillows@epitech.net>
//
// Started on  Sat Jul 16 16:34:49 2016 Stéphane lejeune
// Last update Tue Jul 19 23:00:39 2016 Victorien LE COUVIOUR--TUFFET
//

#include "BigDecimal.hpp"
#include "Double.hpp"
#include "Factory.h"
#include "Float.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "ToolBox.hpp"

IOperand *
Factory::createOperand(eOperandType const & e, std::string const & value)
{
  IOperand *(* const tab[])(const std::string &) =
    {
      &Factory::createInt8,
      &Factory::createInt16,
      &Factory::createInt32,
      &Factory::createFloat,
      &Factory::createDouble,
      &Factory::createBigDecimal,
    };
  return(tab[e](value));
}

IOperand *	Factory::createInt8(std::string const & value)		{ return (new Int8(value)); }
IOperand *	Factory::createInt16(std::string const & value)		{ return (new Int16(value)); }
IOperand *	Factory::createInt32(std::string const & value)		{ return (new Int32(value)); }
IOperand *	Factory::createFloat(std::string const & value)		{ return (new Float(value)); }
IOperand *	Factory::createDouble(std::string const & value)	{ return (new Double(value)); }
IOperand *	Factory::createBigDecimal(std::string const &value)	{ return (new BigDecimal(value)); }
