#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP
#include <iostream>


namespace ft {
            template<class Category, class T, class Distance = std::ptrdiff_t,
                     class Pointer = T*, class Reference = T&>
            struct iterator_base {
                public:
                  typedef T         value_type;
                  typedef Distance  difference_type;
                  typedef Pointer   pointer;
                  typedef Reference reference;
                  typedef Category  iterator_category;
}; }


#endif