#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
//# include "_iterators_traits.hpp"
# include "Iterator.hpp"
namespace ft{
template <class T>
class reverse_iterator
{

	public:

		typedef T iterator_type;
		//typedef  iterator<T>::iterator iterator;
	//	ty
		typedef typename _iterators_traits<iterator_type>::value_type        value_type;
    	typedef typename _iterators_traits<iterator_type>::difference_type   difference_type;
    	typedef typename _iterators_traits<iterator_type>::pointer           pointer;
   		typedef typename _iterators_traits<iterator_type>::reference         reference;
		reverse_iterator(pointer lop = nullptr)
		{
			_iter = lop;
		}
		
		reverse_iterator( reverse_iterator const & src ): _iter (src)
		{
		}
		~reverse_iterator()
		{

		}
		reverse_iterator& operator+=(difference_type n)
		{
				_iter -= n;
				return *this;
		}
		reverse_iterator& operator+(difference_type n)
		{
			//+everse_iterator  temp = *this;
			//temp -= n;
			return reverse_iterator(_iter - n);
		}
		reverse_iterator& operator-=(difference_type n)
		{
				_iter -= n;
				return *this;
		}
		reverse_iterator operator-(difference_type n)
		{
			//iterator  temp1 = *this;
			//temp1 += n;
			return reverse_iterator(_iter + n);
		}
		difference_type &operator-(reverse_iterator& rhs)
		{
			return (*this - rhs);
		}
		value_type &operator[](difference_type n)
		{
			return _iter[-n -1];
		}
		bool operator!=(const reverse_iterator& rhs)
		{
			return (*this != rhs);
		}
		bool operator>(reverse_iterator& rhs)
		{	
			return (*this < rhs);
		}
		bool operator<(reverse_iterator& rhs)
		{
			return (*this > rhs);
		}
		bool operator<=(reverse_iterator& rhs)
		{
			return (*this >= rhs);
		}
		bool operator>=(reverse_iterator& rhs)
		{
			return (*this <= rhs);
		}
		reverse_iterator operator--(int)
		{
			T tmp = *this;
			++tmp;
			return reverse_iterator(tmp);
		}
		
		reverse_iterator operator--()
		{
			++_iter;
			return reverse_iterator(*this);
		}
		reverse_iterator operator++(int)
		{
			T tmp = *this;
			--tmp;
			return reverse_iterator(tmp);
		}
		
		reverse_iterator operator++()
		{
			_iter--;
			return reverse_iterator(_iter);
		}
		value_type &operator*()
		{
			return *--_iter;
		}
		//pointer get_pointer() const
		//{
		//	return Pointer;
		//}



		bool			operator==(reverse_iterator const &rhs)
		{
			if (_iter == rhs)
			return true;
			else
			return false;
		}
		
		

		reverse_iterator 		&operator=( reverse_iterator const & rhs )
		{
			_iter = rhs;
			return *this;
		}

	private:
		T	_iter;

};
};
// template <class T>
// std::ostream &			operator<<( std::ostream & o, iterator<T> const & i )
// {
	// o<<(i.get_pointer());
// }

#endif /* ******************************************************** ITERATOR_H */