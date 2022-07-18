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

		size_type size() const
		{
			return _size;
		}
		size_type max_size() const
		{
			//return (2^(64-size(T))-1);
			return x.max_size();
		}
	//	void resize(size_type sz, T c = T());
		void reserve (size_type n)
		{
			if (n > _capacity)
			{
				pointer op;
				op = x.allocate(n);
				for (int i = 0; i < _size; i++)
				{
					x.construct(op + i, arr[i]);
					x.destroy(arr + i);
				}
				x.deallocate(arr, _size);
				_capacity = n;
				arr = op;
			}
		}
		iterator begin () const {
			////
			return iter;
		}
		
		size_type capacity() const{
			return _capacity;
		}
		bool empty()const
		{
			if (_size == 0)
				return true;
			return false;
		}
		void resize(size_type n,value_type val = value_type() )
		{
			if (n < _size)
			{
				for (int i = _size; i > n; i--)
				{
					x.destroy(arr + i);
				}
			}
			if (n > _size)
			{
				if (n  > _capacity)
				{
					pointer op;
					op = x.allocate(n);
					for (int i = 0; i < _size; i++)
					{
						x.construct(op + i, arr[i]);
						x.destroy(arr + i);
					}
					for (int i = _size; i < n; i++)
					{
						x.construct(op + i, val);
					}
					x.deallocate(arr, _size);
					_size = n;
					_capacity = n;
					arr = op;
				}
				else
				{
					for (int i = _size; i < n; i++)
					{
						x.construct(arr + i, val);
					}
				}
			}
		}

		void pop_back()
		{
			x.destroy(arr + (_size - 1));
			//if (size)
			_size = _size - 1;
		}
		
		explicit Vector (const allocator_type& alloc = allocator_type())
		{
			arr = nullptr;
			_size = 0;
			_capacity = 0;
			x = alloc;
		}

		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			arr = x.allocate(n);
			_size = n;
			for (size_type i = 0; i < n; i++)
			{
				x.construct(this->arr + i, val);
			}
		//	std::cout << "DOOOONE_00" << std::endl;
		//	for (size_type i = 0; i < n; i++)
		//	{
		//		std::cout << arr[i] << std::endl;
		//	}
		//	std::cout << "DOOOONE_01" << std::endl;
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