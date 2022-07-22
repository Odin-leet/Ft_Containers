#ifndef _ITERATORS_TRAITS_HPP
# define _ITERATORS_TRAITS_HPP

# include <iostream>
# include <string>
template <class T>
class _iterators_traits
{


	public:

		_iterators_traits();
		_iterators_traits( _iterators_traits const & src );
		~_iterators_traits();

		_iterators_traits &		operator=( _iterators_traits const & rhs );
		typedef ptrdiff_t difference_type;
   		typedef T value_type;
    	typedef T* pointer;
    	typedef T& reference;
    //	typedef random_access_iterator_tag iterator_category;

	private:

};

//std::ostream &			operator<<( std::ostream & o, _iterators_traits const & i );

#endif /* *********************************************** _ITERATORS_TRAITS_H */