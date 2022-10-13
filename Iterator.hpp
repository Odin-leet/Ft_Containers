#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include "iterator_base.hpp"

namespace ft{
template <class T>
class iterator : public ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >
{
	
	public:

		typedef T iterator_type;
		//typedef Iterator<T> iterator;
		typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::value_type        value_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::difference_type   difference_type;
    	typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::pointer           pointer;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::reference         reference;
   		typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::iterator_category         iterator_category;
	protected:
		pointer	Pointer;
		//T allo;
	public : 
	//template<class InputIterator>
// 	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
//	{
//		
//	}
		iterator(pointer lop = NULL)
		{
			 Pointer  = lop;
		}
		//iterator( iterator const & src ): Pointer (src.Pointer)
		//{
		//}
		pointer base() const { return Pointer; }

		template<typename _Iter>
		iterator(const iterator<_Iter>& __i) : Pointer(__i.base()) { };
		
		~iterator()
		{

		}
		iterator& operator+=(difference_type n)
		{
				Pointer += n;
				return *this;
		}
		iterator operator+(difference_type n)
		{
			return (iterator(Pointer + n));
		}
		iterator& operator-=(difference_type n)
		{
				Pointer -= n;
				return *this;
		}
		difference_type operator-(iterator rhs)
		{
			difference_type s = 
			Pointer - rhs.Pointer;
			return (s);
		}
		iterator operator-(difference_type n)
		{
			return (iterator (Pointer - n));
		}
		
		reference operator[](difference_type n)
		{
			return (*(Pointer + n));
		}

		iterator operator--(int)
		{
			return(iterator(Pointer--));
		}
		
		iterator &operator--()
		{
			--Pointer;
			return *this;
		}
		iterator operator++(int)
		{
			return(iterator(Pointer++));
		}
		
		iterator &operator++()
		{
			Pointer++;
			return *this;
		}
		reference operator*()const
		{
			return *(Pointer);
		}
		pointer get_pointer() const
		{
			return Pointer;
		}
		pointer operator->() const
		{
			 return this->Pointer;
		}
		//friend iterator operator + (difference_type n, const iterator  &src )
		//{
		//	return(iterator (src.get_pointer() + n));
		//}

		bool			operator==(const iterator  &rhs)
		{
			if (Pointer == rhs.Pointer)
			return true;
			else
			return false;
		}
		
		

		//}
		//operator iterator<con
		
		
		//+st T>()
		//{
		//	return (iterator<const T>(Pointer));
		//}
		iterator 		&operator=( const iterator  & rhs )
		{
			Pointer = rhs.Pointer;
			return *this;
		}
	

};

template <class Iterator>
  bool operator==(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return (x.base() == y.base());
  }
template <class Iterator>
  bool operator<(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return (x.base() < y.base());
  }
template <class Iterator>
  bool operator!=(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return (x.base() != y.base());
  }
template <class Iterator>
  bool operator>(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return (x.base() > y.base());
  }
	template <class Iterator>
  bool operator>=(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return !(x.base() < y.base());
  }
template <class Iterator>
  bool operator<=(const iterator<Iterator>& x, const iterator<Iterator>& y)
  {
	return !(x.base() > y.base());
  }

template <class Iterator>
  iterator<Iterator> operator+( typename iterator<Iterator>::difference_type n, const iterator<Iterator>& x)
  {
	return(iterator<Iterator>(x.base() + n));
  }
};

// template <class T>
// std::ostream &			operator<<( std::ostream & o, iterator<T> const & i )
// {
	// o<<(i.get_pointer());
// }

#endif /* ******************************************************** ITERATOR_H */

//template <t1,t2>
//operator > ( t1 , t2)