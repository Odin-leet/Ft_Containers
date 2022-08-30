#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include "_iterators_traits.hpp"

namespace ft{
template <class T>
class iterator
{

	public:

		typedef T iterator_type;
		typedef typename _iterators_traits<iterator_type>::value_type        value_type;
    	typedef typename _iterators_traits<iterator_type>::difference_type   difference_type;
    	typedef typename _iterators_traits<iterator_type>::pointer           pointer;
   		typedef typename _iterators_traits<iterator_type>::reference         reference;
   		typedef typename _iterators_traits<iterator_type>::iterator_category         iterator_category;
		iterator(pointer lop = NULL)
		{
			 Pointer  = lop;
		}
		//consiterator (con)
		iterator( iterator const & src ): Pointer (src.Pointer)
		{
		}
		~iterator()
		{

		}
		iterator& operator+=(difference_type n)
		{
				Pointer += n;
				return *this;
		}
		iterator& operator+(difference_type n)
		{
			iterator  temp = *this;
			temp += n;
			return (temp);
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
			iterator  temp1 = *this;
			temp1 -= n;
			return (temp1);
		}
		
		value_type &operator[](difference_type n)
		{
			return (*(Pointer + n));
		}
		bool operator!=(const iterator& rhs)
		{
			return (Pointer != rhs.Pointer);
		}
		bool operator>(iterator& rhs)
		{	
			return (*this - rhs > 0);
		}
		bool operator<(iterator& rhs)
		{
			return (*this - rhs < 0);
		}
		bool operator<=(iterator& rhs)
		{
			return (*this - rhs >= 0);
		}
		bool operator>=(iterator& rhs)
		{
			return (*this - rhs <= 0);
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			tmp.Pointer--;
			return tmp;
		}
		
		iterator operator--()
		{
			--Pointer;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			tmp.Pointer++;
			return tmp;
		}
		
		iterator operator++()
		{
			Pointer++;
			return *this;
		}
		value_type &operator*()
		{
			return *(Pointer);
		}
		pointer get_pointer() const
		{
			return Pointer;
		}
		pointer operator->()
		{
			return (Pointer);
		}
		friend iterator operator + (difference_type n, const iterator  &src )
		{
			return(iterator (src.get_pointer() + n));
		}

		bool			operator==(const iterator  &rhs)
		{
			if (Pointer == rhs.Pointer)
			return true;
			else
			return false;
		}
		
		
		operator iterator<const T>()  const
		{
			return *(Pointer);
		}
		
//
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

	private:
		pointer	Pointer;

};
};

// template <class T>
// std::ostream &			operator<<( std::ostream & o, iterator<T> const & i )
// {
	// o<<(i.get_pointer());
// }

#endif /* ******************************************************** ITERATOR_H */