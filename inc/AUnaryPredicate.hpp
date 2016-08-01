//
// AUnaryPredicate.hpp for cpp_plazza in /home/lecouv/rendu/cpp_plazza
// 
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv@epitech.eu>
// 
// Started on  Wed Apr 13 19:05:26 2016 Victorien LE COUVIOUR--TUFFET
// Last update Wed Apr 13 19:05:39 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef AUNARYPREDICATE_HPP_
# define AUNARYPREDICATE_HPP_

namespace	UnaryPredicate
{
  template<typename T, typename U>
  class			AUnaryPredicate
  {
  public:
    AUnaryPredicate(T const & data) : _data(data) {}
    virtual ~AUnaryPredicate(void) {}
    virtual bool	operator()(U const &) const = 0;

  protected:
    T			_data;
  };
}

#endif /* !AUNARYPREDICATE_HPP_ */
