#include "AVL_TREE.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AVL_TREE::AVL_TREE()
{
}

AVL_TREE::AVL_TREE( const AVL_TREE & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AVL_TREE::~AVL_TREE()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AVL_TREE &				AVL_TREE::operator=( AVL_TREE const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AVL_TREE const & i )
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