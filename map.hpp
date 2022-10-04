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
    typedef	AVL_TREE<Key, T> 				tree;
    typedef bintree_node<Key,T>     bintre;
    typedef typename Allocator::reference			reference;
    		typedef typename std::size_t size_type;

    typedef typename Allocator::const_reference		const_reference;
	  typedef typename Allocator::pointer				pointer;
	  typedef typename Allocator::const_pointer		const_pointer;
    typedef typename tree::iterator iterator;
    //  typedef Bidirectional_iterator<value_type> iterator;
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
  private:
  tree mytree;
  public :
explicit map (const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
{
 // bintre *Root; 
  
}
iterator begin()
{
  return mytree.begin();
}
iterator end()
{
  return mytree.end();
}
map& operator= ( map& x)
{
    tree  replacetree;
    if (mytree.empty() == 0)
    mytree.free_tree1();
    iterator it = x.begin();
    ft::pair<Key ,T> c;
    while (it != x.end())
    {
      c = make_pair(it->first, it->second);
      replacetree.insert1(c);
      it++;
    }
    mytree = replacetree;

    return *this;

}
		template <class InputIterator>  
void insert (InputIterator first, InputIterator last)
{
  mytree.insert(first, last);
}

iterator insert(iterator position, const value_type &val)
		{
			return mytree.insert(position,val);			
		}
ft::pair<iterator, bool> insert(const value_type &val)
{
  return mytree.insert(val);
}
void insert1(const ft::pair<Key,T> &p)
{
  mytree.insert1(p);

};
		size_type erase (const key_type& k)
		{
			return mytree.erase(k);

		}
  void erase (iterator position)
		 {
			mytree.erase(position);
		 }
		
void printmymap()
{
  mytree.print();
  //mytree.print();
  // iterator endd = end();
  // iterator it = begin();
  // while (it != endd)
  // {
  //   std::cout<<"key : "<<it->first<<std::endl;
  //   it++;
  // }
}
};
}
#endif /* ************************************************************* MAP_H */
