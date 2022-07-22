#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include "_iterators_traits.hpp"

template <class T>
class Iterator
{

	public:

		Iterator()
		{
			Pointer = nullptr;
		}
		
		Iterator( Iterator const & src ): Pointer (src.Pointer)
		{
		}
		~Iterator();
		typedef Iterator iterator_type;
		typedef typename _iterators_traits<iterator_type>::value_type        value_type;
    	typedef typename _iterators_traits<iterator_type>::difference_type   difference_type;
    	typedef typename _iterators_traits<iterator_type>::pointer           pointer;
   		typedef typename _iterators_traits<iterator_type>::reference         reference;
		Iterator& operator+=(difference_type n)
		{
				Pointer += n;
				return *this;
		}
		Iterator operator+(difference_type n)
		{
			Iterator  temp = *this;
			temp += n;
			return (temp);
		}
		Iterator& operator-=(difference_type value)
		{
				Pointer -= n;
				return *this;
		}
		Iterator operator-(difference_type value)
		{
			Iterator  temp = *this;
			temp -= n;
			return (temp);
		}
		difference_type operator-(Iterator& rhs)
		{
			return (*this->Pointer - rhs.Pointer);
		}
		value_type operator[](difference_type n)
		{
			return (*(this->Pointer + n));
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
			return (*this - rhs => 0);
		}
		bool operator>=(Iterator& rhs)
		{
			return (*this - rhs =< 0);
		}
		value_type operator*()
		{

		}


		


		
		Iterator &		operator=( Iterator const & rhs );

	private:
		pointer	*Pointer;

};

//std::ostream &			operator<<( std::ostream & o, Iterator const & i );

#endif /* ******************************************************** ITERATOR_H */