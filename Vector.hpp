#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "utilities.hpp"
# include <iostream>
# include <string>
# include "reverse_iterator.hpp"
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
		typedef iterator<const T>				const_iterator;
		typedef iterator<T>						iterator;
	//	typedef iterator<const T>				const_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;
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
		//	if (_capacity == 0)
		//		_capacity = 1;
			if (_size< _capacity)
			{
				x.construct(arr + _size, val);		
				_size++;
			}
			else
			{
				pointer op;
				if (_capacity == 0)
				{
					op = x.allocate(1);
					_capacity = 1;
					_size = 1;
					x.construct(op, val);
				arr = op;
				}
				else
				{

				
				op = x.allocate(_capacity * 2);
				
				for (int i = 0; i < _size; i++)
				{
					x.construct(op + i, arr[i]);
					//if (_size != 0)
					x.destroy(arr + i);
				}
				x.construct(op + _size, val);
				if (_size != 0)
				x.deallocate(arr, _size);
				_size++;
				_capacity = _capacity * 2;
				}
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
		//iterator begin ()  {
		//	////
		//	iterator op(arr);
		//	return op;
		//}
		void insert (iterator position, iterator first,iterator last)
		{
			int n = 0;
			iterator first2 = first;
			for (iterator pos1 = first; pos1 != last ; pos1 += 1)
			{
				n++;
				//std::cout<<"sadsadasdas"<<std::endl;
			}
			//n--;
			pointer op;
			iterator pos2;
			int i = 0;
			pos2 = begin();
			if (_capacity <= (_size + n))
			{
				op = x.allocate(_size + n);
				_size += n;
				_capacity+= n;
			}
			else
			{
				_size +=n;
				op = x.allocate(_size);
			}
			//op = x.allocate( _size);
			while (pos2 != position && i < _size)
			{
				x.construct(op + i, arr[i]);
				x.destroy(arr + i);
				pos2+= 1;
				i++;
			}
			for(int j = 0; j < n;j++)
			{
				x.construct(op + i, *first2);
				first2+= 1;
				i++;
			}
			while (i < _size)
			{
				x.construct(op + i,arr[i - n]);
				x.destroy(arr + (i - n));
				i++;
			}
			x.deallocate(arr, _size - n);
			arr = op;
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			pointer op;
			iterator pos2;
			int i = 0;
			pos2 = begin();
			if (_capacity <= (_size + n))
			{
				op = x.allocate(_size + n);
				_size += n;
				_capacity+= n;
			}
			else
			{
				_size +=n;
				op = x.allocate(_size);
			}
			//op = x.allocate( _size);
			while (pos2 != position && i < _size)
			{
				x.construct(op + i, arr[i]);
				x.destroy(arr + i);
				pos2+= 1;
				i++;
			}
			for(int j = 0; j < n;j++)
			{
				x.construct(op + i, val);
				i++;
			}
			while (i < _size)
			{
				x.construct(op + i,arr[i - n]);
				x.destroy(arr + (i - n));
				i++;
			}
			x.deallocate(arr, _size - n);
			arr = op;
			//return(position);
		}
		iterator insert (iterator position, const value_type& val)
		{
			pointer op;
			iterator pos2;
			int i = 0;
			pos2 = begin();
			if (_capacity <= _size)
			{
				op = x.allocate(_capacity + 1);
				_size++;
				_capacity++;
			}
			else
			{
				_size++;
				op = x.allocate(_size);
			}
			//op = x.allocate( _size);
			while (pos2 != position && i < _size)
			{
				x.construct(op + i, arr[i]);
				x.destroy(arr + i);
				pos2+= 1;
				i++;
			}
			x.construct(op + i, val);
			i++;
			while (i < _size)
			{
				x.construct(op + i,arr[i - 1]);
				x.destroy(arr + (i - 1));
				i++;
			}
			x.deallocate(arr, _size - 1);
			arr = op;
			return(position);

		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		iterator begin ()  {
			////
			iterator op(arr);
			return (op);
		}
		const_iterator begin() const{
			const_iterator op(arr);
			return (op);
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
		void swap (Vector& I)
		{
			std::swap (_size ,I._size);
			std::swap (_capacity ,I._capacity);
			std::swap (arr, I.arr);
			const allocator_type& alloc = x;
			//alloc = T;
			//alloc = x;
			x = I.x;
			I.x = alloc;
			//std::swap(x, x.x);


		}
		template < class L>
		void assign (typename enable_if<!is_integral<L>::value, L>::type first , L last)
		{
			int i = 0;
			for (int i = 0; i < _size; i++)
			{
				x.destroy(arr + i);
			}
			x.deallocate(arr, _size);
			iterator it = first;
			while (first != last)
			{
				push_back(*first);
				first+= 1;
			}

		}
		void assign (size_type n, const value_type& val)
		{
			int i = 0;
			for (int i = 0; i < _size; i++)
			{
				x.destroy(arr + i);
			}
			x.deallocate(arr, _size);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		void pop_back()
		{
			x.destroy(arr + (_size - 1));
			_size = _size - 1;
		}
		iterator erase (iterator first, iterator last)
		{
			int i = 0;
			iterator firs1;
			iterator first2;
			for (iterator first1 = first; first1 != last; first1+= 1)
			{
				i++;
			}
			iterator reminder = first;

			for (iterator op = first; i > 0; i--)
			{
				erase(op);
			}
			return(reminder);
			
		}
		iterator erase (iterator position)
		{
				iterator pos1 = position;
				pos1+= 1;
				iterator pos2 = position;
				pos2+= 1;
				//ite
				if (pos1  == end())
				{
					x.destroy(position.get_pointer());
					_size--;
				}
			  else
			  {
				for (iterator it = position; it != end() - 1; it += 1)
				{
					

					iterator op = it;
					op+= 1;
					if (op == end())
					{
						break;
					}
					else
					*it = *op;
					if (op == end() - 1)
					{
						x.destroy(op.get_pointer());
					}
				}
				_size--;
			  }
			 // position += 1;
			  return position;
		}
		//iterator erase (iterator first, iterator last);
		void clear()
		{
			for(int i = 0; i < _size; i++)
			{
				x.destroy(arr + i);
			}
			_size = 0;
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
			_capacity = n;
			for (size_type i = 0; i < n; i++)
			{
				x.construct(this->arr + i, val);
			}

			x = alloc;
		}
		template <class P>
		Vector (typename enable_if<!is_integral<P>::value, P>::type first, P last, const allocator_type& alloc = allocator_type())
		{
			std::cout<<"allo"<<std::endl;
			while (first != last)
			{
				push_back(*first);
				first+= 1;
			}
		}
	//	Vector(const Vector<T,Allocator>& x);
		~Vector() {}
		//template <class InputIterator>
        // Vector (InputIterator first, InputIterator last,
        //         const allocator_type& alloc = allocator_type());
		////typedef std::reverƒstse_iterator<iterator>			reverse_iterator;
		//typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
		reference front()
		{
			return (*(arr));
		}
		reference back()
		{
			return(*(arr + (_size - 1)));
		}
		const_reference at (size_type n) const
		{
			return(*(arr + n));
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