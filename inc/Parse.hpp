//
// Parse.hh for Parse in /home/lejeun_b/rendu/Tek_2/C++/NanoTakeSpice/cpp_nanotekspice
//
// Made by Stéphane Lejeune
// Login   <lejeun_b@epitech.net>
//
// Started on  Mon Feb 15 17:01:43 2016 Stéphane Lejeune
// Last update Wed Jul 20 14:58:57 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <regex.h>
#include <list>
#include "IComponent.hpp"
#include "ToolBox.hpp"

namespace	Component
{
  class			Parse : public IComponent
  {
  public:
    Parse(void);
    Parse(Parse const &) = delete;
    virtual ~Parse(void);

    void			feed(std::string const & line);
    void			checkSyntax(void);

    virtual IComponent &	operator<<(IComponent &);
    void			operator>>(std::list<std::string> & words);

  private:
    std::list<std::string>	_lines;

    void			_checkEntity(std::list<std::string>::iterator & it);
  };
}

#endif /* ! PARSE_HPP */
