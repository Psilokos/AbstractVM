//
// ToolBox.cpp for tools in /home/lecouv_v/rendu/cpp_indie_studio
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Sun May 22 07:57:28 2016 Victorien LE COUVIOUR--TUFFET
// Last update Fri Jun  3 19:03:05 2016 Victorien LE COUVIOUR--TUFFET
//

#include <algorithm>
#include "ToolBox.hpp"
#include "UnaryPredicate.hpp"

namespace	ToolBox
{
  Color::Color(unsigned const r, unsigned const g, unsigned const b, unsigned const a)
    : a(a), r(r), g(g), b(b) {}
  Color::~Color(void) {}

  Exception::Exception(std::string const & msg) : _msg(msg) {}
  Exception::~Exception(void) throw() {}

  char const *
  Exception::what(void) const throw() { return (_msg.c_str()); }

  std::list<std::string>
  tokenize(std::string const & s, std::string const & seq)
  {
    std::string::const_iterator		lastIt;
    std::string::const_iterator		it = s.begin();
    std::list<std::string>		tokens;

    do
      {
	if ((lastIt = find_if(it, s.end(), UnaryPredicate::SeqNotCmp(seq))) == s.end())
	  break ;
	it = find_if(lastIt, s.end(), UnaryPredicate::SeqCmp(seq));
	tokens.push_back(std::string(s, std::distance(s.begin(), lastIt),
				     std::distance(lastIt, it)));
	lastIt = it;
      } while (it != s.end());
    return (tokens);
  }
}
