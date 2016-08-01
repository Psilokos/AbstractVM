/*
** Factory.h for abstractVM in /home/lecouv_v/rendu/abstractVM
**
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.eu>
**
** Started on  Tue Jul 19 19:53:57 2016 Victorien LE COUVIOUR--TUFFET
** Last update Tue Jul 19 20:04:10 2016 Victorien LE COUVIOUR--TUFFET
*/

#ifndef FACTORY_H
# define FACTORY_H

#include <iostream>
#include <string>
#include "IOperand.hpp"

class	Factory
{
 public:
  typedef IOperand *	(Factory::*pfct)(const std::string &);

  static IOperand*		createOperand(eOperandType const & e, std::string const & value);
  static IOperand*		createInt8(std::string const & value);
  static IOperand*		createInt16(std::string const & value);
  static IOperand*		createInt32(std::string const & value);
  static IOperand*		createFloat(std::string const & value);
  static IOperand*		createDouble(std::string const & value);
  static IOperand*		createBigDecimal(std::string const & value);
};

#endif/*! FACTORY_H */
