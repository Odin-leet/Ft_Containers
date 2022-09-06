#include "iterator_traits.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
tenp
iterator_traits::iterator_traits()
{
}

iterator_traits::iterator_traits( const iterator_traits & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

iterator_traits::~iterator_traits()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

iterator_traits &				iterator_traits::operator=( iterator_traits const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, iterator_traits const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */