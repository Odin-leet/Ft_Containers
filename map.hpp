#ifndef MAP_HPP
# define MAP_HPP
# include <map>

# include <iostream>
# include <string>
#include "Bidirectional_iterator.hpp"
namespace ft{
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Allocator = std::allocator<pair<const Key, T> > >  // map::allocator_type
           
class map
{
  public :
	  typedef Key										key_type;
    typedef T										mapped_type;
    typedef ft::pair<const Key, T>					value_type;
    typedef Compare									key_compare;
    typedef Allocator								allocator_type;
    typedef typename Allocator::reference			reference;
    typedef typename Allocator::const_reference		const_reference;
	  typedef typename Allocator::pointer				pointer;
	  typedef typename Allocator::const_pointer		const_pointer;
    typedef Bidirectional_iterator<const value_type> const_iterator;
    typedef Bidirectional_iterator<value_type> iterator;
    //typedef 
	class value_compare
          : public std::binary_function<value_type,value_type,bool> {
        friend class map;
        protected:
          Compare comp;
          value_compare(Compare c) : comp(c) {}
        public:
          bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
}
};
explicit map (const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
{ 
}

};
}
#endif /* ************************************************************* MAP_H */
