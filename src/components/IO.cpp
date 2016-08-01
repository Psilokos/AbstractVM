//
// IO.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 19:28:53 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 14:22:28 2016 Victorien LE COUVIOUR--TUFFET
//

#include <string>
#include "Chipset.hpp"
#include "IO.hpp"
#include "ToolBox.hpp"

namespace	Component
{
  IO::IO(std::istream & input, std::ostream & output) : _is(input), _os(output) {}
  IO::~IO(void) {}

  std::string &
  IO::operator>>(std::string & line)
  {
    if (!_is.eof())
      {
	std::getline(_is, line);
	if (!_is.eof())
	  {
	    if (_is.bad())
	      throw ToolBox::Exception("IO: Read error on input operation");
	    if (_is.fail())
	      throw ToolBox::Exception("IO: Logical error on input operation");
	  }
	if (line == ";;")
	  line.clear();
      }
    return (line);
  }

  IComponent &
  IO::operator<<(IComponent & sb)
  {
    std::string		line;

    _os << (dynamic_cast<Component::Chipset::SouthBridge &>(sb) >> line) << std::endl;
    if (_os.bad())
      throw ToolBox::Exception("IO: Write error on output operation");
    if (_os.fail())
      throw ToolBox::Exception("IO: Logical error on output operation");
    return (*this);
  }
}
