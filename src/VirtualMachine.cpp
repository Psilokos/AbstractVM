//
// VirtualMachine.cpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 11:55:55 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Jul 20 15:10:51 2016 Victorien LE COUVIOUR--TUFFET
//

#include "Chipset.hpp"
#include "CPU.hpp"
#include "Exit.hpp"
#include "IO.hpp"
#include "MMU.hpp"
#include "Parse.hpp"
#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine(std::istream & input, std::ostream & output)
{
  _components[Component::ComponentType::ChipsetSB] = new Component::Chipset::SouthBridge();
  _components[Component::ComponentType::ChipsetNB] = new Component::Chipset::NorthBridge();
  _components[Component::ComponentType::CPU] = new Component::CPU();
  _components[Component::ComponentType::IO] = new Component::IO(input, output);
  _components[Component::ComponentType::MMU] = new Component::MMU();
}

VirtualMachine::~VirtualMachine(void)
{
  for (auto it = _components.begin(); it != _components.end(); ++it)
    delete (it->second);
}

void
VirtualMachine::run(void)
{
  Component::Parse			parser;
  std::string				line;
  std::list<std::string>		words;
  std::list<Component::Communication>	communications;
  bool					exceptionRaised = false;
  bool					exitExceptionRaised = false;

  while ((dynamic_cast<Component::IO &>(*_components[Component::ComponentType::IO]) >> line).length())
    parser.feed(line);
  parser.checkSyntax();
  while (!exitExceptionRaised)
    {
      *_components[Component::ComponentType::CPU]
	<< (*_components[Component::ComponentType::ChipsetNB]
	    << (*_components[Component::ComponentType::ChipsetSB] << parser));
      try
	{
	  while (dynamic_cast<Component::CPU &>
		 (*_components[Component::ComponentType::CPU])(exceptionRaised))
	    {
	      dynamic_cast<Component::CPU &>
		(*_components[Component::ComponentType::CPU]) >> communications;
	      try
		{
		  for (auto it = communications.begin();
		       it != communications.end();
		       it = communications.erase(it))
		    *_components[it->inComponent] << *_components[it->outComponent];
		}
	      catch (Component::MMU::Exception const & e)
		{
		  exceptionRaised = true;
		}
	    }
	  if (exceptionRaised)
	    exceptionRaised = false;
	}
      catch (Subroutine::ExitException const & e)
	{
	  exitExceptionRaised = true;
	}
    }
}
