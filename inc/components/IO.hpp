//
// IO.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 19:29:48 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 18:01:04 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef IO_HPP_
# define IO_HPP_

# include <istream>
# include <iostream>
# include <ostream>
# include "IComponent.hpp"

namespace	Component
{
  class		IO : public IComponent
  {
  public:
    IO(std::istream & input, std::ostream & output);
    IO(IO const &) = delete;
    virtual ~IO(void);

    virtual IComponent &	operator<<(IComponent & sb);
    std::string &		operator>>(std::string & line);

  private:
    std::istream &	_is;
    std::ostream &	_os;
  };
}

#endif /* !IO_HPP_ */
