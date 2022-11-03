#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
//#include "map.hpp"
#include <iostream>
#include <string>
#include "pair.hpp"
#include "vector.hpp"
#include "reverse_iterator.hpp"
#include "Bidirectional_iterator.hpp"
template <class Type>
struct rebind
{
	typedef std::allocator<Type> other;
};
 int cglobal ;
 int jglobal ;
namespace ft
{

	template <class Tc>
		struct bintree_node
		{
			bintree_node *left;
			bintree_node *right;
			bintree_node *parent;
			Tc data;
			bool inserted;
			int height;
		};
	template <class key, class T2, class Compare = std::less<key>, class Allocator = std::allocator<ft::pair<key, T2> > >
		class AVL_TREE
		{
			public :

			int imroot;
			private:

			Compare cmp;

			public:
			typedef ft::pair<key, T2> value;
			typedef typename Allocator::template rebind<bintree_node<value> >::other alloccc;
			typedef bintree_node<value> treenode;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef T2 value_type;
			typedef key key_type;
			typedef typename Allocator::pointer pointer;
			typedef Allocator allocator_type;
			typedef typename std::size_t size_type;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::Bidirectional_iterator<value, treenode, Compare> iterator;
			typedef ft::Bidirectional_iterator<const value, treenode, Compare> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			bintree_node<value> *Root;
			bintree_node<value> *imtheEnd;
			allocator_type x;

			size_type _size;
			private:
			alloccc c;

			public:
			AVL_TREE(treenode *node = NULL)
			{
				cglobal = 0;
				jglobal = 0;
				Root = node;
				//	alloccc c;
				imroot = 0;
				_size = 0;
				imtheEnd = c.allocate(1);
				jglobal++;
				imtheEnd->parent = NULL;
				imtheEnd->left = NULL;
				imtheEnd->left = NULL;
				imtheEnd->right = Root;
				//imroot = 0;
			}


			treenode *newnode(const ft::pair<key, T2> &p, treenode *parent, treenode *node, const allocator_type &alloc = allocator_type())
			{
				x = alloc;
				alloccc c;
				(void)node;
				treenode *newno = c.allocate(1);
				jglobal ++;
				newno->left = imtheEnd;
				newno->right = imtheEnd;
				newno->parent = parent;
				x.construct(&newno->data, p);
				// newno->data  = x.construct(p÷;
				newno->height = 1;
				newno->inserted = true;
				return newno;
			}
				void free_tree2()
			{
				if (_size != 0 && Root != NULL && Root != imtheEnd)
				free_tree(Root);
				//imroot = 0;
				imroot = 1;
				_size = 0;
				Root = NULL;
			}
			void free_tree1()
			{
				if (_size != 0 && Root != NULL && Root != imtheEnd)
				free_tree(Root);
				if (imtheEnd != NULL)
				{
				c.deallocate(imtheEnd, 1);
				imtheEnd = NULL;
				}
				//imroot = 0;
				imroot = 1;
				_size = 0;
				Root = NULL;
			}
			void free_tree(treenode *node)
			{
				treenode *tmp = node;
				treenode *tmp1;
				treenode *tmp2;
				tmp1 = node->right;
				tmp2 = node->left;
				c.deallocate(tmp, 1);
				tmp = NULL;
				cglobal++;
				if (tmp1 != imtheEnd)
				{
					free_tree(tmp1);
				}
				if (tmp2 != imtheEnd)
				{
					free_tree(tmp2);
				}
				//tmp = NULL;
				return;
			}
			treenode *searchforkey(const key_type &x, treenode *node) const
			{
				treenode *replace;
				int a = 0;
				int b = 0;
				replace = node;
				if(node != NULL && node != imtheEnd)
					if (node->data.first == x)
						return replace;
				// if (replace->left != imtheEnd && replace-> right != imtheEnd)
				//{
				if (replace->left != imtheEnd && (cmp(x, replace->data.first)))
				{
					a = 1;
					replace = searchforkey(x, replace->left);
				}
				else 
				{
					if (replace->right != imtheEnd)
					{
						b = 1;
						replace = searchforkey(x, replace->right);

					}
				}
				//
				if (a == 0 && b == 0)
					replace = NULL;
				return replace;
			}

			treenode *lowkeyofroot(treenode *root1) const
			{
				treenode *replace = root1;
				// replace = root;
				if (replace->left != imtheEnd)
					if (!(cmp(replace->data.first, replace->left->data.first)))
					{
						replace = lowkeyofroot(replace->left);
					};
				if (replace->right != imtheEnd)
					if (!(cmp(replace->data.first, replace->right->data.first)))
					{
						replace = lowkeyofroot(replace->right);
					};
				return replace;
			}
			// the node lies behind of given node
			treenode *get_myPredecessor(treenode *node)
			{
				treenode *replace;
				if (node->left != imtheEnd)
				{
					// treenode * replace;
					replace = node->left;
					while (replace->right != imtheEnd && replace->right != NULL)
					{
						replace = replace->right;
					}
					return (replace);
				}
				else
				{
					replace = node->parent;
					while (replace->parent != imtheEnd)
					{
						if (cmp(get_myPredecessor(replace->parent)->data.first, node->data.first))
							return get_myPredecessor(replace->parent);
					}
					// else
					return NULL;
				}
				return imtheEnd;
			}
			// the node lies ahead of given node
			treenode *get_mySuccessor(treenode *node)
			{
				if (node->right != imtheEnd)
				{
					treenode *replace;
					replace = node->right;
					while (replace->left != imtheEnd)
					{
						replace = replace->left;
					}
					return (replace);
				}
				return imtheEnd;
			}
			// Rotate right
			treenode *rightRotate(treenode *y)
			{
				treenode *x = y->left;
				treenode *T3 = x->right;
				treenode *parentrep = y->parent;

				y->parent = x;
				x->parent = parentrep;
				x->right = y;
				y->left = T3;
				if(T3 != imtheEnd && T3 != NULL)
					T3->parent = y;
				y->height = max(height(y->left),
						height(y->right)) +
					1;
				x->height = max(height(x->left),
						height(x->right)) +
					1;
				return x;
			}

			// Rotate left
			treenode *leftRotate(treenode *x)
			{
				treenode *y = x->right;
				treenode *T3 = y->left;
				treenode *parentrep = x->parent;
				y->parent = parentrep;
				x->parent = y;
				y->left = x;
				x->right = T3;
				if(T3 != imtheEnd && T3 != imtheEnd)
					T3->parent = x;
				x->height = max(height(x->left),
						height(x->right)) +
					1;
				y->height = max(height(y->left),
						height(y->right)) +
					1;
				return y;
			}
			int height(treenode *N)
			{
				if (N == NULL || N == imtheEnd)
					return 0;
				return N->height;
			}
			int getBalanceFactor(treenode *N)
			{
				if (N == imtheEnd)
					return 0;
				return height(N->left) -
					height(N->right);
			}

			int max(int a, int b)
			{
				return (a > b) ? a : b;
			}
			treenode *nodeWithMimumValue(treenode *node)
			{
				treenode *current = node;
				while (current->left != imtheEnd)
					current = current->left;
				return current;
			}

			iterator find (const key_type& k)
			{
				treenode *node;
				node =  searchforkey(k, Root);
				if (node == NULL)
					return iterator(imtheEnd);
				return (iterator(node));
			}
			const_iterator find (const key_type& k) const
			{
				treenode *node;
				node =  searchforkey(k, Root);
				if (node == NULL)
					return const_iterator(imtheEnd);
				return (const_iterator(node));
			}
			// { CAPACITY }
			bool empty() const
			{
				if (_size == 0)
					return true;
				return false;
			}

			size_type size() const
			{
				return _size;
			}
			size_type max_size() const
			{
				return c.max_size();
			}
			// 23.3.1.2 element access:
			T2 &operator[](const key_type &x)
			{
				treenode *thenode;
				ft::pair<key, T2> p;
				 
				p = ft::make_pair(x, T2());
				thenode = NULL;
				if (Root != NULL)
					thenode = searchforkey(x, Root);
				if (thenode == NULL)
				
					{
					Root = insert_elements(Root, imtheEnd, p);
					imtheEnd->right = Root;
					}
				else
					return thenode->data.second;
				thenode = searchforkey(x, Root);
				return thenode->data.second;
			}
			 T2& at (const key_type& k)
			 {
				treenode *thenode;
				thenode = NULL;
				if (Root != NULL)
					thenode = searchforkey(k, Root);
				if (thenode == NULL)
				{
					throw std::out_of_range("ERROR");
				}
				return thenode->data.first;
				
			 }
			 const T2& at (const key_type& k) const
			 {
				treenode *thenode;

				thenode = NULL;
				if (Root != NULL)
					thenode = searchforkey(k, Root);
				if (thenode == NULL)
				{
					throw std::out_of_range("ERROR");
				}
				return thenode->data.first;
			 }
			iterator end()
			{
				if(Root == NULL)
					return(iterator(NULL));
				return iterator(imtheEnd);
			}
			iterator begin()
			{
				if(Root == NULL || Root == imtheEnd)
					return(iterator(NULL));
				return iterator(lowkeyofroot(Root));
			}
			const_iterator end() const
			{
				if(Root == NULL)
					return(const_iterator(NULL));
				return const_iterator(imtheEnd);
			}
			const_iterator begin() const
			{	
				if(Root == NULL)
					return(const_iterator(NULL));
				return const_iterator(lowkeyofroot(Root));
			}
			ft::pair<iterator, bool> insert(const ft::pair<const key, T2> &p)
			{
				// std::cout<<"im the root in this place : "<<Root<<std::endl;
				treenode *pop;
				Root = insert_elements(Root, imtheEnd, p);
				//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
				imtheEnd->right = Root;
				//print();
				pop = searchforkey(p.first, Root);
				iterator it(Root);
				ft::pair<iterator, bool> m;
				if (pop->inserted == true)
					m = ft::make_pair(iterator(pop), true);
				else
					m = ft::make_pair(iterator(pop), false);

				return (m);
				//	std::cout<<"im the root in after that other place : "<<Root<<std::endl;
				// it.printmyend(Root);
				//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
			}
			// pair *getnextnode(pair)
			void insert1(const ft::pair<key, T2> &p)
			{
				// std::cout<<"im the root in this place : "<<Root<<std::endl;

				Root = insert_elements(Root, imtheEnd, p);
				//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
				imtheEnd->right = Root;
				//iterator it(Root);
				//	std::cout<<"im the root in after that other place : "<<Root<<std::endl;
				// it.printmyend(Root);
				//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
			}
			template <class InputIterator>
				void insert(InputIterator first, InputIterator last)
				{
					while (first != last)
					{
						//printTree(Root, "", true);
						ft::pair<key, T2> P = ft::make_pair(first->first, first->second);
						Root = insert_elements(Root, imtheEnd, P);
						first++;
					}
						imtheEnd->right = Root;
				}
			iterator insert(iterator position, const ft::pair<key, T2> &val)
			{
				(void)position;
				// iterator pos1 = position;
				//pos1 = NULL;
				treenode *pop;
				Root = insert_elements(Root, imtheEnd, val);
				imtheEnd->right = Root;
				pop = searchforkey(val.first, Root);
				return iterator(pop);
			}
			//   void erase (iterator position);
			size_type erase (const key_type& k)
			{
				size_type op = _size;
			
				Root = deleteNode(Root, k);
				if (_size != op)
					return (1);
				return 0;

			}
			void erase (iterator position)
			{
				ft::pair<key, T2> val;
				val = ft::make_pair(position->first, position->second);
				Root = deleteNode(Root, position->first);
			}

			void erase (iterator first, iterator last)
			{
				if (Root != NULL && Root != imtheEnd)
			{
				ft::pair<key, T2> val;
				ft::vector<key> myvector;
				while (first != last)
				{
					myvector.push_back(first->first);
					first++;
				}
;
				size_type i = 0;
				key c;
				while(i < myvector.size())
				{
					Root = deleteNode(Root, myvector[i]);
					c = myvector[i];
					i++;

				}
			}
			}

			// something not working here x
			treenode *insert_elements(treenode *node, treenode *parent, const ft::pair<key, T2> &p)
			{
				if ((node == NULL || node == imtheEnd))
				{
					_size++;
					return newnode(p, parent, NULL);
				}
				else if (node != imtheEnd && node != NULL)
				{

					if (node->data.first == p.first)
					{
						node->inserted = false;
						return node;
					}
				}

				if (cmp(p.first, node->data.first))
				{
					node->left = insert_elements(node->left, node, p);
				}
				else
				{
					node->right = insert_elements(node->right, node, p);
				}
				//print();
				node->height = 1 + max(height(node->left),
						height(node->right));
				int balanceFactor = getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (cmp(p.first,node->left->data.first))
					{
						return rightRotate(node);
					}
					else
					{
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}
				}
				if (balanceFactor < -1)
				{
					if (!cmp(p.first,node->right->data.first))
					{
						return leftRotate(node);
					}
					else
					{
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}
				}
				return (node);
			}
			size_type count (const key_type& k) const
			{
				treenode *node;
				node =  searchforkey(k, Root);
				if (node == NULL)
					return 0;
				return 1;
			}
			AVL_TREE &operator=(const AVL_TREE& rhs) 
        {
				if (Root != NULL)
				{

				free_tree(Root);
				}
				Root = NULL;
			insert(rhs.begin(), rhs.end());
			_size = rhs._size;
            return (*this);
        };
		 void insert_nodes(treenode *node, treenode *theend)
        {
            if (node == theend)
                return;
            insert1(node->data);
            if (node->left != theend)
                insert_nodes(node->left, theend);
            if (node->right != theend)
                insert_nodes(node->right, theend);
        }
			void print()
			{
				printTree(Root, "", true);
			}
			void printTree(treenode *node, std::string indent, bool last)
			{
				//	treenode *node ;
				if (node != imtheEnd && node != NULL)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
						if(node->parent->data != NULL)
							std::cout << "parent : " << node->parent->data.first << std::endl;
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
						if(node->parent->data != NULL)
							std::cout << "parent : " << node->parent->data.first << std::endl;
					}
					std::cout << node->data.first << std::endl;

					printTree(node->left, indent, false);
					printTree(node->right, indent, true);
				}
			}

			// delete node
			// treenode *lower_bound(const key_type& k)
			// {
			// 	treenode
			// }
			treenode *deleteNode(treenode *node, key_type p)
			{
                if (node == imtheEnd)
					return node;
                if (cmp(p, node->data.first) )
					node->left = deleteNode(node->left, p);
				else if (cmp (node->data.first,p) )
					node->right = deleteNode(node->right, p);
        
                else{
					if ((node->left == imtheEnd) ||
							(node->right == imtheEnd))
					{
						treenode *temp;
						if (node->left != imtheEnd)
						{
							temp = node->left;
						}
						else
							temp = node->right;
						if (temp == imtheEnd)
						{

							temp = node;
							if (node->parent != imtheEnd && cmp(temp->data.first, node->parent->data.first))
								node->parent->left = imtheEnd;
							else
								node->parent->right = imtheEnd;
							c.deallocate(node,1);
							cglobal++;
							
						//	node = imtheEnd;
							_size--;
							return imtheEnd;
						}
						else
						{
							treenode *tmp2 = node->parent;

							*node = *temp;
							node->parent = tmp2;
							//x.deallocate(temp->data, 1);
							c.deallocate(temp,1);
							cglobal++;
							_size--;
						}
					}
					else
					{
						treenode *temp = nodeWithMimumValue(node->right);
						node->data = temp->data;
						//node->parent = temp->parent;
						node->right = deleteNode(node->right,
								temp->data.first);
					}
				}
				
					 if (node == imtheEnd)
    					return node;
				
				node->height = 1 + max(height(node->left),
						height(node->right));
				int balanceFactor = getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (getBalanceFactor(node->left) >= 0)
					{
						return rightRotate(node);
					}
					else
					{
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}
				}
				if (balanceFactor < -1)
				{
					if (getBalanceFactor(node->right) <= 0)
					{
						return leftRotate(node);
					}
					else
					{
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}
				}
				return node;
			}
				void swap(AVL_TREE &x)
				{

				 std::swap(Root, x.Root);
				 
          		  std::swap(_size, x._size);
				  std::swap(imtheEnd, x.imtheEnd);
           	//  std::swap(mytree.cmp, x.mytree.cmp);
         	//    std::swap(this->_alloc, other._alloc);//to check
        	//     std::swap(this->_alloc_node, other._alloc_node);//to check
						//  std::swap (mytree, x.mytree);
						//  std::swap  (mytree.Root, x.mytree.Root);ƒƒ
						//  std::swap (mytree.imtheEnd, x.mytree.imtheEnd);
						//  std::swap (mytree._size, x.mytree._size);
					 
				}
			
			
			~AVL_TREE()
			{	
				//if (imroot == 0)
				//	std::cout <<"im distr tree"<<std::endl;
					free_tree1();
				//while (1);
				//std::cout<<"what i allocated = " <<jglobal<<"   what i freed  == "<<cglobal<<std::endl;
				//jglobal = 0;
				//cglobal = 0;
			//	c.deallocate(imtheEnd, 1);
			//	while (1);
				//if ()
			}

			
			};
		}

#endif /* ******************************************************** AVL_TREE_H */
