#ifndef iterator_traits_HPP
# define iterator_traits_HPP

# include <iostream>
# include <string>
template <class T>
class iterator_traits
{


	public:

		iterator_traits();
		iterator_traits( iterator_traits const & src );
		~iterator_traits();

		iterator_traits &		operator=( iterator_traits const & rhs );
		typedef ptrdiff_t diference_type;
   		typedef T value_type;
    	typedef T* pointer;
    	typedef T& reference;
    //	typedef random_access_iterator_tag iterator_category;

	private:

};

//std::ostream &			operator<<( std::ostream & o, iterator_traits const & i );

#endif /* *********************************************** iterator_traits_H */