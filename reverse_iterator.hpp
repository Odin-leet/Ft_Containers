#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
# include "iterator_traits.hpp"

namespace ft{
template <class T>
class reverse_iterator
{

	public:

		typedef T iterator_type;
		//typedef  iterator<T>::iterator iterator;
	//	ty
		typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type        value_type;
    	typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
    	typedef typename iterator_traits<iterator_type>::pointer           pointer;
   		typedef typename iterator_traits<iterator_type>::reference         reference;
		  typedef reverse_iterator<T> _Self;
		protected:
		T	_iter;
		public :
		reverse_iterator()
		{
		}
		
		reverse_iterator( T src ): _iter (src)
		{
		}
		iterator_type base() const { return _iter; }
		template <class _Iter>
   		reverse_iterator(const reverse_iterator<_Iter>& __x) : _iter(__x.base()) {}
		~reverse_iterator()
		{

		}
  		_Self& operator+=(difference_type n)
		{
		
				_iter -= n;
				return *this;
		}
		_Self operator+(difference_type n) const
		{
			//+everse_iterator  temp = *this;
			//temp -= n;
			T tmp = _iter;
			return _Self(tmp - n);
		}
		_Self& operator-=(difference_type n)
		{
				_iter += n;
				return *this;
		}
		_Self operator-(difference_type n) const
		{
			//iterator  temp1 = *this;
			//temp1 += n;
			T tmp = _iter;
			return _Self(tmp + n);
		}
		reference operator*() const
		{
			//_iter--;
			T tmp(_iter);
			return *(--tmp);
		} 
		pointer operator->() const
		{
			 return &(operator*());
		}

		reference operator[](difference_type n) const
		{
			T tmp = _iter;
			return tmp[-n -1];
		}
		_Self operator--(int)
		{
			_Self tmp;
			tmp = *this;
			++_iter;
			return tmp;
		}
		_Self &operator--()
		{
			++_iter;
			return *this;
		}
		_Self operator++(int)
		{
			//T tmp = *this;
			_Self tmp = *this;
			--_iter;
			return tmp;
		}
		
		_Self &operator++()
		{
			--_iter;
			return *this;
		}

		bool			operator==(reverse_iterator const &rhs)
		{
			if (_iter == rhs._iter)
			return true;
			else
			return false;
		}
		
		bool			operator!=(reverse_iterator const &rhs)
		{
			if (_iter != rhs._iter)
			return true;
			else
			return false;
		}
		



};
template <class Iterator>
  bool operator==(const reverse_iterator<Iterator>& x,  const reverse_iterator<Iterator>& y)
  {
	return (x.base() == y.base());
  }
template <class Iterator>
  bool operator<(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
  {
	return(x.base() > y.base());
  }
template <class Iterator>
  bool operator!=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
  {
	return(x.base() != y.base());
  }
template <class Iterator>
  bool operator>(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
  {
	return(x.base() < y.base());
  }
	template <class Iterator>
  bool operator>=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
  {
	return(x.base() <= y.base());
  }
template <class Iterator>
  bool operator<=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y)
  {return(x.base() >= y.base());

  }
template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
  {
	return (y.base() - x.base());
  }
template <class Iterator>
  reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& x)
  {
	return reverse_iterator<Iterator>( x.base() - n );
  }
//template <class Iterator>
// typename reverse_iterator<Iterator>::diffrence_type operator-( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
//  {
//	return  x.base() - y.base() ;
//  }
};
// template <class T>
// std::ostream &			operator<<( std::ostream & o, iterator<T> const & i )
// {
	// o<<(i.get_pointer());
// }

#endif /* ******************************************************** ITERATOR_H */