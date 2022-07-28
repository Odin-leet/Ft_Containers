#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "Iterator.hpp"
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
		
		typedef typename Allocator::pointer				pointer;
		typedef Iterator<T>						iterator;
		// 23.2.4.2 capacity:
		typedef Allocator								allocator_type;
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
		void push_back (const value_type& val)
		{
			if (_size< _capacity)
			{
				x.construct(arr + _size, val);		
				_size++;
			}
			else
			{
				pointer op;
				op = x.allocate(_capacity * 2);
				for (int i = 0; i < _size; i++)
				{
					x.construct(op + i, arr[i]);
					x.destroy(arr + i);
				}
				x.construct(op + _size, val);
				x.deallocate(arr, _size);
				_size++;
				_capacity = _capacity * 2;
				arr = op;
			}
		}
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
		iterator begin ()  {
			////
			iterator op(arr);
			return op;
		}
		iterator end()	{
			iterator op(arr + _size);
			return op;
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
		//Iterator

		void pop_back()
		{
			x.destroy(arr + (_size - 1));
			_size = _size - 1;
		}
		iterator erase (iterator position)
		{
			  if (position + 1 != end())
			  {
				for (iterator it = begin(); it != end(); it+= 1)
				{
					if (it == position)
					{
						//x.destroy(arr + i);
						

					}
					i++;
				}
			  }
		}
		iterator erase (iterator first, iterator last);
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
			_capacity = n;
			for (size_type i = 0; i < n; i++)
			{
				x.construct(this->arr + i, val);
			}

			x = alloc;
		}
		Vector(const Vector<T,Allocator>& x);
		~Vector() {}
		
		//typedef std::reverƒstse_iterator<iterator>			reverse_iterator;
		//typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
		reference front()
		{
			return (*(arr));
		}
		reference back()
		{
			return(*(arr + (_size - 1)));
		}

		reference at (size_type n)
		{
			return(*(arr + n));
			//throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size).
			//This is in contrast with member operator[], that does not check against bounds.

		}
		reference operator[] (size_type n)
		{
			return(*(arr + n));
		}
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