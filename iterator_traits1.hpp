#include <iostream>



template<class T> struct iterator_traits<T> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef std::bidirectional_iterator_tag iterator_category;
};
