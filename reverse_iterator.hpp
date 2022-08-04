#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
# include "_iterators_traits.hpp"

template <class T>
class reverse_iterator
{

	public:

		typedef T iterator_type;
		typedef typename _iterators_traits<iterator_type>::value_type        value_type;
    	typedef typename _iterators_traits<iterator_type>::difference_type   difference_type;
    	typedef typename _iterators_traits<iterator_type>::pointer           pointer;
   		typedef typename _iterators_traits<iterator_type>::reference         reference;
		reverse_iterator(pointer lop = nullptr)
		{
			Pointer = lop;
		}
		
		reverse_iterator( Iterator const & src ): Pointer (src.Pointer)
		{
		}
		~reverse_iterator()
		{

		}
		reverse_iterator& operator+=(difference_type n)
		{
				Pointer -= n;
				return *this;
		}
		reverse_iterator& operator+(difference_type n)
		{
			Iterator  temp = *this;
			temp -= n;
			return (temp);
		}
		reverse_iterator& operator-=(difference_type n)
		{
				Pointer -= n;
				return *this;
		}
		reverse_iterator operator-(difference_type n)
		{
			Iterator  temp1 = *this;
			temp1 += n;
			return (temp1);
		}
		difference_type &operator-(reverse_iterator& rhs)
		{
			return (*this->Pointer - rhs.Pointer);
		}
		value_type &operator[](difference_type n)
		{
			return (*(Pointer + n));
		}
		bool operator!=(const reverse_iterator& rhs)
		{
			return (Pointer != rhs.Pointer);
		}
		bool operator>(reverse_iterator& rhs)
		{	
			return (*this - rhs > 0);
		}
		bool operator<(reverse_iterator& rhs)
		{
			return (*this - rhs < 0);
		}
		bool operator<=(reverse_iterator& rhs)
		{
			return (*this - rhs >= 0);
		}
		bool operator>=(reverse_iterator& rhs)
		{
			return (*this - rhs <= 0);
		}
		reverse_iterator operator--(int)
		{
			Iterator tmp = *this;
			++Pointer;
			return *this;
		}
		
		reverse_iterator operator--()
		{
			++Pointer;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			Iterator tmp = *this;
			--Pointer;
			return *this;
		}
		
		reverse_iterator operator++()
		{
			--Pointer;
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



		bool			operator==(reverse_iterator const &rhs)
		{
			if (Pointer == rhs.Pointer)
			return true;
			else
			return false;
		}
		
		

		reverse_iterator 		&operator=( reverse_iterator const & rhs )
		{
			Pointer = rhs.Pointer;
			return *this;
		}

	private:
		pointer	Pointer;

};

// template <class T>
// std::ostream &			operator<<( std::ostream & o, Iterator<T> const & i )
// {
	// o<<(i.get_pointer());
// }

#endif /* ******************************************************** ITERATOR_H */