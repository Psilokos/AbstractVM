//
// UnaryPredicate.hpp for cpp_plazza in /home/lecouv/rendu/cpp_plazza
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv@epitech.eu>
//
// Started on  Wed Apr 13 19:07:00 2016 Victorien LE COUVIOUR--TUFFET
// Last update Sun Apr 24 00:30:08 2016 moisse_r
//

#ifndef UNARYPREDICATE_HPP_
# define UNARYPREDICATE_HPP_

# include <string>
# include "AUnaryPredicate.hpp"

namespace	UnaryPredicate
{
  class			SeqCmp : AUnaryPredicate<std::string, char>
  {
  public:
    SeqCmp(std::string const & seq) : AUnaryPredicate(seq) {}
    virtual ~SeqCmp(void) {}

    virtual bool	operator()(char const & c) const
    { return (_data.find(c) != std::string::npos); }
  };

  class			SeqNotCmp : AUnaryPredicate<std::string, char>
  {
  public:
    SeqNotCmp(std::string const & seq) : AUnaryPredicate(seq) {}
    virtual ~SeqNotCmp(void) {}

    virtual bool	operator()(char const & c) const
    { return (_data.find(c) == std::string::npos); }
  };
}

#endif /* !UNARYPREDICATE_HPP_ */
