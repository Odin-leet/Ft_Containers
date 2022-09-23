#ifndef BIDIRECTIONAL_ITERATOR_HPP 
#define BIDIRECTIONAL_ITERATOR_HPP
//#include "Avl_tree.hpp"
#include "iterator_traits.hpp"
#include "iterator_base.hpp"
#include <iostream>


namespace ft{
template <class T, class data>
class Bidirectional_iterator : public ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> > 
{
    public:

		typedef T iterator_type;
		//typedef Iterator<T> iterator;
		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::value_type        value_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::difference_type   difference_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::pointer           pointer;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::reference         reference;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::iterator_category         iterator_category;
	private:
		data *node;
		data *root;
		data *end;
		pointer pair;
		// hnaya 
		data * returningmyroot(data *replace)
		{
			// data *replace;
			end = NULL;
			int checker = 1;
			std::cout<<"im the root in after that place  in returning: "<<replace<<std::endl;
			// replace = node;
			while (replace->parent != NULL)
			{
				std::cout<<"im here "<<"\n";
				replace = replace->parent;
			}
			end = replace;
			std::cout<<"im the root in after that place  in returning: 1  "<<replace->right<<std::endl;

			return (replace->right);
			//root->parent
		}
	public : 

		

		Bidirectional_iterator(data *lop = NULL)
		{
			if (lop != NULL)
			node = lop;
					//	std::cout<<"im the root in after that place  in returning: 3 "<<node<<std::endl;

			//{
		//	returningmyroot();
			root = returningmyroot(node);
							//		std::cout<<"im the root in after that place  in returning: 4 "<<root<<std::endl;

			if (node != NULL && node != end)
			pair = &node->data;
			//else
			//{
			//							//			std::cout<<"im the root in after that place  in returning: 55"<<root<<std::endl;
//
			//root = NULL;
			//end = NULL;
			//}
		}

		void printmyend(data *node1)
		{
			std::cout<<&end<<std::endl;
			std::cout<<&root<<std::endl;
		}
		reference operator*() const {
			return *pair;
		}
		pointer * base() const { return pair; }
		 template<typename _iterator, typename Data1>
		 Bidirectional_iterator(const Bidirectional_iterator <_iterator, Data1> & i ) : node(i->data), pair(i->pair){
			if (node != NULL)
			{
				returningmyroot();
			}
		 };

		 Bidirectional_iterator &operator=(const Bidirectional_iterator &rhs)
		 {
			node = rhs->node;
			pair = rhs->pair;
		 }
		 Bidirectional_iterator operator++(int)
		 {

		 }
		pointer operator->() const
		{
			 return this->pair;
		}

};

template <class Iterator, class data>
  bool operator==(const Bidirectional_iterator<Iterator, data>& x, const Bidirectional_iterator<Iterator, data>& y)
  {
	return (x.base() == y.base());
  }
template <class Iterator, class data>
  bool operator!=(const Bidirectional_iterator<Iterator, data>& x, const Bidirectional_iterator<Iterator, data>& y)
  {
	return (x.base() != y.base());
  }
}
#endif