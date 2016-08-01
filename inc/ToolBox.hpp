//
// ToolBox.hpp for tools in /home/lecouv_v/rendu/cpp_indie_studio
//
// Made by Victorien LE COUVIOUR--TUFFET
// Login   <lecouv_v@epitech.eu>
//
// Started on  Sun May 22 04:40:40 2016 Victorien LE COUVIOUR--TUFFET
// Last update Fri Jun  3 16:39:38 2016 Victorien LE COUVIOUR--TUFFET
//

#ifndef TOOLBOX_HPP_
# define TOOLBOX_HPP_

# include <cmath>
# include <list>
# include <stdexcept>
# include <string>

namespace	ToolBox
{
  class		Color
  {
  public:
    Color(unsigned const r, unsigned const g, unsigned const b, unsigned const a = 0xff);
    ~Color(void);

    unsigned	a;
    unsigned	r;
    unsigned	g;
    unsigned	b;
  };

  class		Exception : public std::exception
  {
  public:
    explicit Exception(std::string const & msg);
    virtual ~Exception(void) throw();

    char const *	what(void) const throw();

  private:
    std::string		_msg;
  };

  template<typename T>
  class		Vector2
  {
  public:
    Vector2(T x, T y) : x(x), y(y) {}
    Vector2(Vector2<T> const & src) : x(src.x), y(src.y) {}
    ~Vector2(void) {}

    Vector2<T>	operator-(Vector2<T> const & other) { return (Vector2<T>(x - other.x, y - other.y)); }
    Vector2<T>	operator+(Vector2<T> const & other) { return (Vector2<T>(x + other.x, y + other.y)); }
    Vector2<T>	operator*(Vector2<T> const & other) { return (Vector2<T>(x * other.x, y * other.y)); }
    Vector2<T>	operator/(Vector2<T> const & other) { return (Vector2<T>(x / other.x, y / other.y)); }
    Vector2<T>	operator%(Vector2<T> const & other) { return (Vector2<T>(x % other.x, y % other.y)); }

    Vector2<T> &	operator-=(Vector2<T> const & other)
    {
      x -= other.x;
      y -= other.y;
      return (*this);
    }
    Vector2<T> &	operator+=(Vector2<T> const & other)
    {
      x += other.x;
      y += other.y;
      return (*this);
    }
    Vector2<T> &	operator*=(Vector2<T> const & other)
    {
      x *= other.x;
      y *= other.y;
      return (*this);
    }
    Vector2<T> &	operator/=(Vector2<T> const & other)
    {
      x /= other.x;
      y /= other.y;
      return (*this);
    }
    Vector2<T> &	operator%=(Vector2<T> const & other)
    {
      x %= other.x;
      y %= other.y;
      return (*this);
    }
    Vector2<T>	operator=(Vector2<T> const & src)
    {
      if (&src != this)
	{
	  x = src.x;
	  y = src.y;
	}
      return (*this);
    }

    bool	operator<(Vector2<T> const & other)
    { return (::sqrt(::pow(x - other.x, 2) + ::pow(y - other.y, 2)) < 0); }
    bool	operator>(Vector2<T> const & other)
    { return (::sqrt(::pow(x - other.x, 2) + ::pow(y - other.y, 2)) > 0); }
    bool	operator<=(Vector2<T> const & other)
    { return (::sqrt(::pow(x - other.x, 2) + ::pow(y - other.y, 2)) <= 0); }
    bool	operator>=(Vector2<T> const & other)
    { return (::sqrt(::pow(x - other.x, 2) + ::pow(y - other.y, 2)) >= 0); }
    bool	operator!=(Vector2<T> const & other) { return (x != other.x && y != other.y); }
    bool	operator==(Vector2<T> const & other) { return (x == other.x && y == other.y); }

    T		x;
    T		y;
  };

  std::list<std::string>	tokenize(std::string const & s, std::string const & seq);
}

#endif /* !TOOLBOX_HPP_ */
