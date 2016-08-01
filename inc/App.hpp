//
// App.hpp for abstractVM in /home/lecouv_v/rendu/abstractVM
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Thu Jul 14 17:38:00 2016 Victorien LE COUVIOUR--TUFFET
// Last update Tue Jul 19 01:42:26 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef APP_HPP_
# define APP_HPP_

# include "VirtualMachine.hpp"

class		App
{
public:
  App(void);
  App(App const &) = delete;
  ~App(void);

  void		run(int const argc, char *argv[]);

private:
  VirtualMachine *	_vm;
};

#endif /* !APP_HPP_ */
