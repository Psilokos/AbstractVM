//
// Parse.cpp for abstractVM in
//
// Made by Stéphane lejeune
// Login   <thepillows@epitech.net>
//
// Started on  Tue Jul 19 10:49:50 2016 Stéphane lejeune
// Last update Wed Jul 20 18:01:48 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Parse.hpp"
#include "ToolBox.hpp"

namespace	Component
{
  Parse::Parse(void) {}
  Parse::~Parse(void) {}

  void	Parse::feed(std::string const & line)	{ _lines.push_back(line); }

  void
  Parse::checkSyntax(void)
  {
    for (auto it = _lines.begin(); it != _lines.end();)
      _checkEntity(it);
  }

  IComponent &	Parse::operator<<(IComponent &) { return (*this); }

  void
  Parse::operator>>(std::list<std::string> & words)
  {
    if (_lines.size())
      {
	words = ToolBox::tokenize(_lines.front(), " \t");
	_lines.pop_front();
      }
    else
      words.clear();
  }

  /*
  ** private methods
  */

  void
  Parse::_checkEntity(std::list<std::string>::iterator & it)
  {
    regex_t			regex;
    size_t			comPos;

    if ((comPos = it->find(";")) != std::string::npos)
      it->erase(comPos, it->length() - comPos);
    if (it->length())
      {
	regcomp(&regex, "^(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit)|" \
		"((push|assert|load|store)[ \t]+((int(8|16|32)\\((-?[0-9]+)\\))|(float|double|bigdecimal)\\((-?[0-9]+[.]?[0-9]+)\\)))[ \t]*$",
		REG_EXTENDED);
	if (regexec(&regex, it->c_str(), 0, NULL, 0) == 1)
	  throw ToolBox::Exception("unknown instruction");
	regfree(&regex);
	++it;
      }
    else
      it = _lines.erase(it);
  }
}
