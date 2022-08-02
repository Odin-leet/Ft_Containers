#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include "_iterators_traits.hpp"

template <class T>
class Iterator
{

	public:

		typedef T iterator_type;
		typedef typename _iterators_traits<iterator_type>::value_type        value_type;
    	typedef typename _iterators_traits<iterator_type>::difference_type   difference_type;
    	typedef typename _iterators_traits<iterator_type>::pointer           pointer;
   		typedef typename _iterators_traits<iterator_type>::reference         reference;
		Iterator(pointer lop = nullptr)
		{
			Pointer = lop;
		}
		
		Iterator( Iterator const & src ): Pointer (src.Pointer)
		{
		}
		~Iterator()
		{

		}
		Iterator& operator+=(difference_type n)
		{
				Pointer += n;
				return *this;
		}
		Iterator& operator+(difference_type n)
		{
			Iterator  temp = *this;
			temp += n;
			return (temp);
		}
		Iterator& operator-=(difference_type n)
		{
				Pointer -= n;
				return *this;
		}
		Iterator operator-(difference_type n)
		{
			Iterator  temp1 = *this;
			temp1 -= n;
			return (temp1);
		}
		difference_type &operator-(Iterator& rhs)
		{
			return (*this->Pointer - rhs.Pointer);
		}
		value_type &operator[](difference_type n)
		{
			return (*(Pointer + n));
		}
		bool operator!=(const Iterator& rhs)
		{
			return (Pointer != rhs.Pointer);
		}
		bool operator>(Iterator& rhs)
		{	
			return (*this - rhs > 0);
		}
		bool operator<(Iterator& rhs)
		{
			return (*this - rhs < 0);
		}
		bool operator<=(Iterator& rhs)
		{
			return (*this - rhs >= 0);
		}
		bool operator>=(Iterator& rhs)
		{
			return (*this - rhs <= 0);
		}
		value_type &operator*()
		{
			return *(Pointer);
		}
		pointer get_pointer() const
		{
			return Pointer;
		}



		bool			operator==(Iterator const &rhs)
		{
			if (Pointer == rhs.Pointer)
			return true;
			else
			return false;
		}
		
		

		Iterator 		&operator=( Iterator const & rhs )
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