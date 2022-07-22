#include "_iterators_traits.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
tenp
_iterators_traits::_iterators_traits()
{
}

_iterators_traits::_iterators_traits( const _iterators_traits & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

_iterators_traits::~_iterators_traits()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

_iterators_traits &				_iterators_traits::operator=( _iterators_traits const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, _iterators_traits const & i )
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