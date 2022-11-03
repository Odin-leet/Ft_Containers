#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
namespace ft{
template <class T, class Container = ft::vector<T> > 
class stack
{
  public:
    typedef typename Container::value_type  value_type;
    typedef typename Container::size_type   size_type;
    typedef          Container              container_type;
  protected:
    Container c;
    public:
      explicit stack(const Container& ctnr= Container())
      {
        c = ctnr;
      }
      bool      empty() const           { return c.empty(); }
      size_type size()  const           { return c.size(); }
      value_type&       top()           { return c.back(); }
      const value_type& top() const     { return c.back(); }
      void push(const value_type& x)    { c.push_back(x); }
      void pop()                        { c.pop_back(); }
        template <class T1, class Cont>
        friend bool operator<(const stack<T1, Cont>& lhs, const stack<T1, Cont>& rhs)
        {
            return (lhs.c < rhs.c);
        }


};
  template <class T, class Container>
    bool operator==(const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
       return (!(x < y || y < x) );
    }
  template <class T, class Container>
    bool operator!=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
         return !(x == y);
    }
  template <class T, class Container>
    bool operator> (const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
        return (y < x);
    }
  template <class T, class Container>
    bool operator>=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
        return (!(x < y));
    }
  template <class T, class Container>
    bool operator<=(const stack<T, Container>& x,
                    const stack<T, Container>& y)
    {
        return (!(y < x));
    }

};




#endif
