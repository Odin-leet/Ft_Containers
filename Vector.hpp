#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

template <class X>
class my_allocator
{

};

namespace ft{
template <class T, class Allocator =std::allocator<T> >
class Vector
{


	public:

		//Vector();√v
		

		//Vector( Vector const & src );
		typedef typename Allocator::reference			reference;	
		typedef typename Allocator::const_reference 	const_reference;
		//typedef implementation defined
		//typedef implementation defined
		//typedef implementation defined
		typedef T										value_type;
		
		// 23.2.4.2 capacity:
		typedef Allocator								allocator_type;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef typename std::size_t 						size_type;

		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, T c = T());
		size_type capacity() const;
		bool empty()const;
		void reserve(size_type);
		
		explicit Vector (const allocator_type& alloc = allocator_type())
		{
			arr = nullptr;
			_size = 0;
			_capacity = 0;
			x = alloc;
		}
		//}
		explicit Vector(size_type n, const T& value = T(), const Allocator& = Allocator())
		{
			arr = x.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				x.construct(this->arr + i, value);
			}
			std::cout << "DOOOONE_00" << std::endl;
			for (size_type i = 0; i < n; i++)
			{
				std::cout << arr[i] << std::endl;
			}
			std::cout << "DOOOONE_01" << std::endl;
			x = alloc;
		}
		Vector(const Vector<T,Allocator>& x);
		~Vector() {}
		
		//typedef std::reverse_iterator<iterator>			reverse_iterator;
		//typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;

		Vector &		operator=( Vector const & rhs );

		private:
		pointer  arr;
		allocator_type x;
		size_type _size;
		size_type _capacity;
	
	
};
};

//std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */