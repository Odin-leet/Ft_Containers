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
		

		typedef typename Allocator::reference			reference;	
		typedef typename Allocator::const_reference 	const_reference;
		typedef T										value_type;
		typedef typename Allocator::pointer				pointer;
		typedef iterator<const T>				const_iterator;
		typedef iterator<T>						iterator;
 		typedef reverse_iterator<const_iterator>        const_reverse_iterator;		// 23.2.4.2 capacity:
		typedef reverse_iterator<iterator>				reverse_iterator;
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
		//		_capacity = 1;ƒ
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

		void insert (iterator position, size_type n, const value_type& val)
		{
			pointer op;
			iterator pos2;
			pos2 = begin();
			int position_intial = std::distance(begin(), position);
			int new_size = _size + n;
		//	int i = 0;
			//int reminder = 0;
		//	int old_size = 0;

			if (new_size <= _capacity)
			{
				if(position == end())
				{
					for (int i = _size ; i < new_size ; i++)
					{
						x.construct(arr + i, val);
					}
					_size = new_size;
				}
				else
				{
					int att;// = end() - position;
					att = position_intial + n;
					int i = 0;
					for (int c = position_intial; c < _size;c++)
					{
							x.construct(arr +att , *(arr + position_intial + i ));
							i++;
							att++;
					}
					for (int i = 0; i < n; i++)
					{
						x.construct(arr + position_intial + i, val);
						_size++;
					}
				}
			}
			else
			{
				op = x.allocate(_size);
				for (int i = 0;i < _size; i++)
				{
					x.construct(op + i, *(arr + i));
					x.destroy(arr + i);
				}
			if (_capacity < _size + n && n <= _size)
				_capacity = _capacity * 2;
			else if (_capacity  < _size + n && n > _size)
				_capacity = _capacity + n;
				x.deallocate(arr, _size);
				arr = x.allocate(_capacity );
				if (position == end())
				{
					for(int i = 0; i < _size; i++)
					{
						x.construct(arr + i, *(op + i));
						x.destroy(op + i);
					}
					for(int i = _size; i < _size + n; i++)
					{
						x.construct(arr + i, val);
						_size++;
					}
				}
				else
				{
					for (int i = 0; i < position_intial; i++)
					{
						x.construct(arr + i, *(op + i));
						x.destroy(op + i);
					}
					int att;// = end() - position;
					att = position_intial + n;
					//int i = 0;
					for (int i = 0; i < n; i++)
					{
						x.construct(arr + position_intial + i, val);
					}
					int j = position_intial;
					for (int i = position_intial + n; i < _size + n; i++)
					{
						x.construct(arr + i, *(op + j));
						x.destroy(op + j);
						j++;
					}
					x.deallocate(op,_size);
					_size += n;

				}
			}
		}
		template <class InputIterator>
   		 void insert (iterator position, InputIterator first, InputIterator last)
		{
			pointer op;
			iterator pos2;
			pos2 = begin();
			int position_intial = std::distance(begin(), position);
			int n = std::distance(first, last);
			int new_size = _size + std::distance(first, last);
			//int i = 0;
			// int reminder = 0;
			// int old_size = 0;

			if (new_size <= _capacity)
			{
				if(position == end())
				{
					for (int i = _size ; i < new_size ; i++)
					{
						x.construct(arr + i, *first);
						first++;
					}
					_size = new_size;
				}
				else
				{
					int att;// = end() - position;
					att = position_intial + n;
					int i = 0;
					for (int c = position_intial; c < _size;c++)
					{
							x.construct(arr +att , *(arr + position_intial + i ));
							i++;
							att++;
					}
					for (int i = 0; i < n; i++)
					{
						x.construct(arr + position_intial + i, *first);
						first++;
						_size++;
					}
				}
			}
			else
			{
				op = x.allocate(_size);
				for (int i = 0;i < _size; i++)
				{
					x.construct(op + i, *(arr + i));
					x.destroy(arr + i);
				}
			if (_capacity < _size + n && n <= _size)
				_capacity = _capacity * 2;
			else if (_capacity  < _size + n && n > _size)
				_capacity = _capacity + n;
				x.deallocate(arr, _size);
				arr = x.allocate(_capacity );
				if (position == end())
				{
					for(int i = 0; i < _size; i++)
					{
						x.construct(arr + i, *(op + i));
						x.destroy(op + i);
					}
					for(int i = _size; i < _size + n; i++)
					{
						x.construct(arr + i, *first);
						first++;
						_size++;
					}
				}
				else
				{
					for (int i = 0; i < position_intial; i++)
					{
						x.construct(arr + i, *(op + i));
						x.destroy(op + i);
					}
					int att;// = end() - position;
					att = position_intial + n;
				//	int i = 0;
					for (int i = 0; i < n; i++)
					{
						x.construct(arr + position_intial + i, *first);
						first++;
					}
					int j = position_intial;
					for (int i = position_intial + n; i < _size + n; i++)
					{
						x.construct(arr + i, *(op + j));
						x.destroy(op + j);
						j++;
					}
					x.deallocate(op,_size);
					_size += n;

				}
			}
			
		}

		iterator insert (iterator position, const value_type& val)
		{
			int n = position - begin();
			insert ( position,  1,   val);
			return (begin() + n);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return
			 reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return
			 const_reverse_iterator(begin());
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
		const_iterator end() const{
			const_iterator op(arr + _size);
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
				_size = n;
			}
			else if (n > _size)
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
					_size = n;
				}
			}
		}
		//Iterator
		void swap (Vector& I)
		{
			std::swap (_size ,I._size);
			std::swap (_capacity ,I._capacity);
			std::swap (arr, I.arr);


		}
		template < class InputIterator>
		void assign (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first , InputIterator last)
		{
			_size = 0;
		//	int i = 0;
			for (int i = 0; i < _size; i++)
			{
				x.destroy(arr + i);
			}
			if (_capacity == 0)
			{
				arr = x.allocate(std::distance(first, last));
				_capacity = std::distance(first, last);
			}
			else
			{
				if (_capacity < std::distance(first, last))
				{
				x.deallocate(arr, std::distance(first, last));
				arr = x.allocate(std::distance(first, last));
				_capacity = std::distance(first, last);
				}
			}
			// i = 0;
			// _size = n;
			while (first != last)
			{
				x.construct(arr + _size, *first);
				first++;
				_size++;
			}

		}
		void assign (size_type n, const value_type& val)
		{
			//_size = 0;
			// int i = 0;
			for (int i = 0; i < _size; i++)
			{
				x.destroy(arr + i);
			}
			if (_capacity == 0)
			{
				arr = x.allocate(n);
				_capacity = n;
			}
			else 
			{
				if (_capacity < n)
				{
				x.deallocate(arr, n);
				arr = x.allocate(n);
				_capacity = n;
				}
			}
			for (int i = 0; i < n; i++)
			{
				x.construct(arr + i , val);
			}
			_size = n;
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
		allocator_type get_allocator() const
		{
			return x;
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
			arr = NULL;
			_size = 0;
			_capacity = 0;
			x = alloc;
		}

		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			x = alloc;
			arr = x.allocate(n);
			_size = n;
			_capacity = n;
			for (size_type i = 0; i < n; i++)
			{
				x.construct(this->arr + i, val);
			}

			x = alloc;
		}
		template <class InputIterator>
		Vector (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			x = alloc;
			_size = 0;
			_capacity = std::distance(first, last);
			arr = x.allocate(_capacity);
			while (first != last)
			{
				x.construct(arr + _size, *first);
				first++;
				_size++;
			}
		}
		Vector (const Vector& rhs)
		{

			_size = 0;
			_capacity = rhs.capacity();
			arr = x.allocate(_capacity);
			size_type i = std::distance(rhs.begin(), rhs.end());
			size_type t = 0;
			while (t < i)
			{
				x.construct(arr + _size,  *(rhs.begin() + t));
				_size++;
				t++;
			}

		}
	//	Vector(const Vector<T,Allocator>& x);
		~Vector() {}
		//template <class InputIterator>
        // Vector (InputIterator first, InputIterator last,
        //         const allocator_type& alloc = allocator_type());
		////typedef std::reverƒstse_iterator<iterator>			reverse_iterator;
		//typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;
		const_reference front() const
		{
			return (*(arr));
		}
		const_reference back() const
		{
			return(*(arr + (_size - 1)));
		}
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
			if (n > _size || n == _size)
				throw std::out_of_range("ERROR");
			return(*(arr + n));
			//throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size).
			//This is in contrast with member operator[], that does not check against bounds.

		}
		reference operator[] (size_type n)
		{
			return(*(arr + n));
		}
		const_reference operator[] (size_type n) const
		{
			return(*(arr + n));
		}
		Vector &		operator=( Vector const & rhs )
		{
				
		
			if (_capacity == 0)
			{
				_size = 0;
				arr =  x.allocate(rhs.capacity());
				for(int i = 0 ; i < rhs.size(); i++)
				{
					x.construct(arr + i, *(rhs.begin() + i));
					_size++;
				}
			}
			else
			{
				int i = 0;
				while ( i < _size)
				{
					x.destroy(arr + i);
					i++;
				}
				 x.deallocate(arr , _capacity);
			//	 std::cout<<"capacity === "<<rhs.capacity() << "size == "<<rhs.size()<<std::endl;
				 _size = 0;
				arr = x.allocate(rhs.capacity());
				for(int i = 0 ; i < rhs.size(); i++)
				{
					x.construct(arr + i, *(rhs.begin() + i));
					_size++;
				}
			}
			
			return *this;

		

		}
		

		private:
		pointer  arr;
		allocator_type x;
		size_type _size;
		size_type _capacity;
		
	
	
};
  template <class T, class Allocator>
        bool operator==(const Vector<T,Allocator>& x,const Vector<T,Allocator>& y)
		{
			if (x.size() == y.size())
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i] == y[i])
						continue;
					else
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}; 
      template <class T, class Allocator>
        bool operator< (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
		{
		
				return ft::lexicographical_compare(x.begin(),x.end(), y.begin(), y.end());
	
		}
      template <class T, class Allocator>
        bool operator!=(const Vector<T,Allocator>& x,  const Vector<T,Allocator>& y)
		{
			if (x.size() == y.size())
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (x[i] == y[i])
						continue;
					else
					return true;
				}
			}
			else
			{
				return true;
			}
			return false;
		}
      template <class T, class Allocator>
        bool operator> (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
		{
			return y < x;
		}
      template <class T, class Allocator>
        bool operator>=(const Vector<T,Allocator>& x,  const Vector<T,Allocator>& y)
		{
			return (!(x < y));
		}
		
      template <class T, class Allocator>
        bool operator<=(const Vector<T,Allocator>& x, const Vector<T,Allocator>& y)
		{
			 return (!(x > y));
		}
		template <class T, class Allocator>
            void swap(Vector<T,Allocator>& x, Vector<T,Allocator>& y)
			{			
				x.swap(y);
			}
		};


//std::ostream &			operator<<( std::ostream & o, Vector const & i );

#endif /* ********************************************************** VECTOR_H */ 