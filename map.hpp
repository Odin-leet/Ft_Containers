#ifndef map_HPP
# define map_HPP


# include <iostream>
# include <string>
# include "utili1.hpp"
#include "Avl_tree.hpp"
namespace ft{
	template < class Key,                                     // Map::key_type
		 class T,                                       // Map::Mapped_type
		 class Compare = std::less<Key>,                     // Map::key_compare
		 class Allocator = std::allocator<ft::pair<const Key, T> > >  // Map::allocator_type

			 class Map 
			 {
				 public :
					 typedef Key										            key_type;
					 typedef T										              mapped_type;
					 typedef ft::pair<const Key, T>		          value_type;
					 typedef Compare									          key_compare;
					 typedef Allocator								          allocator_type;
					 typedef	AVL_TREE<Key, T, Compare> 				          tree;
					 typedef bintree_node<Key,T>                bintre;
					 typedef typename Allocator::reference			reference;
					 typedef typename std::size_t size_type;

					 typedef typename Allocator::const_reference		const_reference;
					 typedef typename Allocator::pointer				pointer;
					 typedef typename Allocator::const_pointer		const_pointer;
					 typedef typename tree::const_iterator const_iterator;
					 typedef typename tree::iterator iterator;
					 typedef typename tree::reverse_iterator reverse_iterator;
					 typedef typename tree::const_reverse_iterator const_reverse_iterator;    //typedef 
					 class value_compare
						 : public std::binary_function<value_type,value_type,bool> {
							 friend class Map;
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
					 allocator_type p;
				 public :
				
			// { return (value_compare(key_compare())); }
					 explicit Map (const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
					 {
						 // bintre *Root; 

					 }
					 template <class InputIterator>
						 Map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
						 {
							 mytree.insert(first, last);
						 }
					 Map (const Map& x)
					 {
						 mytree.insert(x.begin(),  x.end());
					 }
					 iterator begin()
					 {
						 return mytree.begin();
					 }
					 iterator end()
					 {
						 return mytree.end();
					 }
					 const_iterator begin() const
					 {
						 return const_iterator (mytree.begin());
					 }
					 const_iterator end() const
					 {
						 return const_iterator (mytree.end());
					 }
					 const_reverse_iterator rbegin() const
					 {
						 return const_reverse_iterator (end());
					 }
					 reverse_iterator rbegin() 
					 {
						 return reverse_iterator(end());
					 }
					 const_reverse_iterator rend() const
					 {
						 return const_reverse_iterator(begin());
					 }
					 reverse_iterator rend() 
					 {
						 return reverse_iterator(begin());
					 }
					 bool empty() const
					 {
						 return mytree.empty();
					 }
					 Map& operator= ( Map& x)
					 {
						 tree  replacetree;
						 if (mytree.empty() == 0)
							 mytree.free_tree1();
						 iterator it = x.begin();
						 ft::pair<Key ,T> c;
						 if(x.size())
							 while (it != x.end())
							 {
								 c = ft::make_pair(it->first, it->second);
								 mytree.insert1(c);
								 it++;
							 }
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
					 void erase (iterator first, iterator last)
					 {
						 mytree.erase(first, last);
					 }

					 size_type erase (const key_type& k)
					 {
						 return mytree.erase(k);
					 }

					 Map& operator= (const Map& x)
					 {
						 mytree = x.mytree;
						 return  *this;
					 }
					 size_type size() const
					 {
						 return mytree.size();
					 }
					 void erase (iterator position)
					 {
						 mytree.erase(position);
					 }
					 void swap(Map &x)
					 {
						int tmptree;
						size_type tmp_size;
						bintre *tmproot;
						bintre *tmpend;


						tmptree = this->mytree.imroot;
						this->mytree.imroot = x.mytree.imroot;
						x.mytree.imroot = tmptree;


						tmp_size = mytree._size;
						mytree._size = x.mytree._size;
						x.mytree._size = tmp_size;

						tmproot = mytree.Root;
						mytree.Root = x.mytree.Root;
						x.mytree.Root = tmproot;

						tmpend = mytree.imtheEnd;
						mytree.imtheEnd = x.mytree.imtheEnd;
						x.mytree.imtheEnd = tmpend;

						//  std::swap (mytree, x.mytree);
						//  std::swap  (mytree.Root, x.mytree.Root);
						//  std::swap (mytree.imtheEnd, x.mytree.imtheEnd);
						//  std::swap (mytree._size, x.mytree._size);
					 }
					 void clear()
					 {
						 if (mytree.empty() == 0)
							 mytree.free_tree1();
					 }
					 iterator find (const key_type& k)
					 {
						 return mytree.find(k);
					 }
					 const_iterator find (const key_type& k) const
					 {
						 return const_iterator(find);
					 }
					 size_type count (const key_type& k) const
					 {
						 return mytree.count(k);
					 }
					 key_compare key_comp() const
					 {
						 return key_compare();
					 }
					 value_compare value_comp() const	
					{
						key_compare c;
						 return value_compare(c);
					}
					 iterator lower_bound (const key_type& k)
					 {
						key_compare c;
						bintre * __y = mytree.imtheEnd; /* Last node which is not less than __k. */
					  bintre * __x = mytree.Root; /* Current node. */
					
					  while (__x != mytree.imtheEnd) 
					    if (!c(__x->data->first, k))
					      __y = __x, __x = __x->left;
					    else
					      __x = __x->right;
					
					  return const_iterator(__y);
						//  iterator allo = begin();
						// // iterator alloend = end();
						//  key_compare cmp;
						//  while (allo.get_node() != allo.get_end())
						//  {
						// 	 if (cmp(allo->first, k) == false)
						// 		 break;
						// 	 allo++;
						//  }
						//  return (allo);

					 }
					 const_iterator lower_bound (const key_type& k) const
					 {
						key_compare c;
						bintre * __y = mytree.imtheEnd; /* Last node which is not less than __k. */
					  bintre * __x = mytree.Root; /* Current node. */
					
					  while (__x != mytree.imtheEnd) 
					    if (!c(__x->data->first, k))
					      __y = __x, __x = __x->left;
					    else
					      __x = __x->right;
					
					  return const_iterator(__y);
						//  iterator allo = begin();
						// // iterator alloend = end();
						//  key_compare cmp;
						//  while (allo.get_node() != allo.get_end())
						//  {
						// 	 if (cmp(allo->first, k) == false)
						// 		 break;
						// 	 allo++;
						//  }
						//  return const_iterator(allo.get_node());
					 }
					 iterator upper_bound (const key_type& k)
					 {
						key_compare c;
						 bintre * __y = mytree.imtheEnd; /* Last node which is greater than __k. */
						  bintre * __x = mytree.Root; /* Current node. */

						   while (__x != mytree.imtheEnd) 
						     if (c(k, __x->data->first))
						       __y = __x, __x = __x->left;
						     else
						       __x = __x->right;

						   return iterator(__y);

					 }
					 const_iterator upper_bound (const key_type& k) const
					 {
					 key_compare c;
						 bintre * __y = mytree.imtheEnd; /* Last node which is greater than __k. */
						  bintre * __x = mytree.Root; /* Current node. */

						   while (__x != mytree.imtheEnd) 
						     if (c(k, __x->data->first))
						       __y = __x, __x = __x->left;
						     else
						       __x = __x->right;

						   return const_iterator(__y);
					 }
					ft::pair<iterator, iterator>
					equal_range(const key_type &k)
					{
						return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
					}
					ft::pair<const_iterator, const_iterator>
					equal_range(const key_type& k) const
					{
						return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
					}
					//  ft::pair<iterator, iterator> equal_range (const key_type& k) const
					//  { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
					allocator_type get_allocator() const
					{
						return p;
					}

					 mapped_type& operator[] (const key_type& k)
					 {
						 return mytree.operator[](k);
					 }
					 //     ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
					 // { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

					 void printmymap()
					 {
						 mytree.print();
					 }
			 };
template< class Key, class T, class Compare, class Alloc >
        bool operator==(const Map<Key,T,Compare,Alloc>& x, const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.size() == y.size())
			{
			 typename ft::Map<Key,T>::iterator it1 = x.begin();
			typename 	ft::Map<Key,T>::iterator it2 = y.begin();
				for (int i = 0; i < x.size(); i++)
				{
					
					if (it1->first == it2->first && it1->second == it2->second )
						continue;
					else
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}; 
      template< class Key, class T, class Compare, class Alloc >
        bool operator< (const Map<Key,T,Compare,Alloc>& x, const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.empty() == true && y.empty() == true)
				return false;
			else if (x.empty() == true && y.empty() != true)
				return true;
			else if (x.empty() == false && y.empty() == true)
				return false;
			else
			{
				if(ft::lexicographical_compare(x.begin(),x.end(), y.begin(), y.end()) == true)
					return true;
			}
			return false;
		}
     template< class Key, class T, class Compare, class Alloc >
        bool operator!=(const Map<Key,T,Compare,Alloc>& x,  const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.size() == y.size())
			{
			typename	 ft::Map<Key,T>::iterator it1 = x.begin();
			typename	ft::Map<Key,T>::iterator it2 = y.begin();
				for (int i = 0; i < x.size(); i++)
				{
					
					if (it1->first == it2->first && it1->second == it2->second )
						continue;
					else
					return true;
				}
			}
			else
			{
				return true;
			}
			return false;
		}
      template< class Key, class T, class Compare, class Alloc >
        bool operator> (const Map<Key,T,Compare,Alloc>& x, const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.empty() == true && y.empty() == true)
				return false;
			else if (x.empty() == true && y.empty() != true)
				return false;
			else if (x.empty() == false && y.empty() == true)
				return true;
			else
			{
				if(ft::lexicographical_compare(y.begin(),y.end(), x.begin(), x.end()) == true)
					return true;
			}
			return false;
		}
    template< class Key, class T, class Compare, class Alloc >
        bool operator>=(const Map<Key,T,Compare,Alloc>& x,  const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.empty() == true && y.empty() == true)
				return false;
			else if (x.empty() == true && y.empty() != true)
				return true;
			else if (x.empty() == false && y.empty() == true)
				return false;
			else
			{
			if(ft::lexicographical_compare2(y.begin(),y.end(), x.begin(), x.end()) == true)
					return true;
			}
			return false;
		}
		
     template< class Key, class T, class Compare, class Alloc >
        bool operator<=(const Map<Key,T,Compare,Alloc>& x, const Map<Key,T,Compare,Alloc>& y)
		{
			if (x.empty() == true && y.empty() == true)
				return false;
			else if (x.empty() == true && y.empty() != true)
				return false;
			else if (x.empty() == false && y.empty() == true)
				return true;
			else
			{
			if(ft::lexicographical_compare2(x.begin(),x.end(), y.begin(), y.end()) == true)
					return true;
			}
			return false;
		}
		template< class Key, class T, class Compare, class Alloc >
            void swap(Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y)
			{			
				x.swap(y);
			}
}
#endif /* ************************************************************* Map_H */
