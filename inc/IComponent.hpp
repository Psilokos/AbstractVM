//
// IComponent.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Fri Jul 15 15:59:21 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 19:40:36 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

namespace	Component
{
  enum class	ComponentType
  {
    ChipsetSB,
      ChipsetNB,
      CPU,
      IO,
      MMU
      };

  struct			Communication
  {
  public:
    ComponentType		inComponent;
    ComponentType		outComponent;

    Communication(ComponentType const & inComponent, ComponentType const & outComponent)
      : inComponent(inComponent), outComponent(outComponent) {}
  };

  class		IComponent
  {
  public:
    virtual ~IComponent(void) {}

    virtual IComponent &	operator<<(IComponent & outComponent) = 0;
  };
}

#endif /* !ICOMPONENT_HPP_ */
