#ifndef BIDIRECTIONAL_ITERATOR_HPP 
#define BIDIRECTIONAL_ITERATOR_HPP
//#include "Avl_tree.hpp"
#include "iterator_traits.hpp"
#include "iterator_base.hpp"
#include <iostream>


namespace ft{
template <class T, class data>
class Bidirectional_iterator : public ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> > 
{
    public:

		typedef data iterator_type;
		//typedef Iterator<T> iterator;
		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> >::value_type        value_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> >::difference_type   difference_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> >::pointer           pointer;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> >::reference         reference;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, data> >::iterator_category         iterator_category;
	private:
		T *node;
		data Data;
	public : 

		Bidirectional_iterator(T *lop = NULL)
		{
			node = lop;
		}
		template<typename _iterator>
		Bidirectional_iterator(const Bidirectional_iterator <_iterator> & i ) : node(i->node), Data (i->data){};

};

}


#endif