//
// VirtualMachine.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 11:57:05 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 01:39:26 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef VIRTUALMACHINE_HPP_
# define VIRTUALMACHINE_HPP_

# include <map>
# include "IComponent.hpp"

class		VirtualMachine
{
public:
  VirtualMachine(std::istream & input, std::ostream & output);
  VirtualMachine(VirtualMachine const &) = delete;
  ~VirtualMachine(void);

  void		run(void);

private:
  std::map<Component::ComponentType, Component::IComponent *>	_components;
};

#endif /* !VIRTUALMACHINE_HPP_ */
