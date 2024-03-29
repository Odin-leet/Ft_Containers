#include <iostream>
//#include <iterator>
// namespace ft {
//              struct input_iterator_tag {};
//              struct output_iterator_tag {};
//              struct forward_iterator_tag: public input_iterator_tag {};
//              struct bidirectional_iterator_tag: public forward_iterator_tag {};
//              struct random_access_iterator_tag: public bidirectional_iterator_tag {};
// }
namespace ft{
   // typedef std::random_access_iterator_tag random_access_iterator_tag;
template<class Iterator> struct iterator_traits     {
        public:
               typedef typename Iterator::difference_type difference_type;
               typedef typename Iterator::value_type value_type;
               typedef typename Iterator::pointer pointer;
               typedef typename Iterator::reference reference;
              // typedef typename Iterator::iterator_category iterator_category;
              typedef typename Iterator::iterator_category iterator_category;
            //   typedef random_access_iterator_tag iterator_category;
};
template<class T> struct  iterator_traits<T*>   {
        public:
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
};
template<class T> struct iterator_traits<const T*>  {
        public : 
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
};

}
	//typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::value_type        value_type;
    	//typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::difference_type   difference_type;
    	//typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::pointer           pointer;
   	//	typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::reference         reference;
   	//	typedef typename ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >::iterator_category         iterator_category;
        //        class iterator : public ft::iterator_traits<ft::iterator_base<std::random_access_iterator_tag, T> >
