#ifndef map_HPP
# define map_HPP


# include <iostream>
# include <string>
# include "utili1.hpp"
# include "Avl_tree.hpp"
namespace ft{
	template < class Key,  class T,  class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >  // Map::allocator_type

		class map 
		{
			public :
				typedef ft::pair< Key, T>		          value_type;
			private:
				typedef bintree_node<value_type>                bintre;
				typedef AVL_TREE<Key, T, Compare> 				          tree;
			public :
				typedef Key										            key_type;
				typedef T										              mapped_type;
				typedef Compare									          key_compare;
				typedef Allocator								          allocator_type;
				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef typename std::size_t size_type;
				typedef typename tree::const_iterator const_iterator;
				typedef typename tree::iterator iterator;
				typedef typename tree::reverse_iterator reverse_iterator;
				typedef typename tree::const_reverse_iterator const_reverse_iterator;    //typedef 
				typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
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
				allocator_type p;
				key_compare c;
				void insert1(const ft::pair<Key,T> &p)
				{
					mytree.insert1(p);

				};
			public :

				explicit map (const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
				{
					p = alloc;
					c = comp;
				}
				template <class InputIterator>
					map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type())
					{
						p = alloc;
						c = comp;
						mytree.insert(first, last);
					}
				map (const map& x)
				{
					mytree.insert(x.begin(),  x.end());
				}
				~map()
				{


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
				size_type max_size() const
				{
					return mytree.max_size();
				}
				bool empty() const
				{
					return mytree.empty();
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

				void erase (iterator first, iterator last)
				{
					mytree.erase(first, last);
				}

				size_type erase (const key_type& k)
				{
					return mytree.erase(k);
				}

				map& operator= (const map& x)
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
				void swap(map &x)
				{
					mytree.swap(x.mytree);
				}
				void clear()
				{
					if (mytree.empty() == 0)
						mytree.free_tree2();
				}
				iterator find (const key_type& k)
				{
					return mytree.find(k);
				}
				const_iterator find (const key_type& k) const
				{
					return mytree.find(k);
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
						if (!c(__x->data.first, k))
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
						if (!c(__x->data.first, k))
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
						if (c(k, __x->data.first))
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
						if (c(k, __x->data.first))
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
				mapped_type& at (const key_type& k)
				{
					return mytree.at(k);
				}
				const mapped_type& at (const key_type& k) const
				{
					return mytree.at(k);
				}

				mapped_type& operator[] (const key_type& k)
				{
					return mytree.operator[](k);
				}
		};
	template< class Key, class T, class Compare, class Alloc >
		bool operator==(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
		{
			if (x.size() == y.size())
			{
				typename ft::map<Key,T>::iterator it1 = x.begin();
				typename 	ft::map<Key,T>::iterator it2 = y.begin();
				for (size_t i = 0; i < x.size(); i++)
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
		bool operator< (const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
		{
			return ft::lexicographical_compare(x.begin(),x.end(), y.begin(), y.end());
		}
	template< class Key, class T, class Compare, class Alloc >
		bool operator!=(const map<Key,T,Compare,Alloc>& x,  const map<Key,T,Compare,Alloc>& y)
		{
			return(!(x == y));
		}
	template< class Key, class T, class Compare, class Alloc >
		bool operator> (const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
		{
			return y < x;
		}
	template< class Key, class T, class Compare, class Alloc >
		bool operator>=(const map<Key,T,Compare,Alloc>& x,  const map<Key,T,Compare,Alloc>& y)
		{
			return (!(x < y));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<=(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
		{
			return (!(x > y));
		}
	template< class Key, class T, class Compare, class Alloc >
		void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{			
			x.swap(y);
		}
}
#endif /* ************************************************************* Map_H */
