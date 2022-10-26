#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
//#include "map.hpp"
#include <iostream>
#include <string>
#include "Pair.hpp"
#include <vector>
#include "reverse_iterator.hpp"
#include "Bidirectional_iterator.hpp"
template <class Type>
struct rebind
{
	typedef std::allocator<Type> other;
};
namespace ft
{

	template <class key, class T2>
		struct bintree_node
		{
			bintree_node *left;
			bintree_node *right;
			bintree_node *parent;
			pair<key, T2> *data;
			bool inserted;
			int height;
		};
	template <class key, class T2, class Compare = std::less<key>, class Allocator = std::allocator<pair<key, T2> > >
		class AVL_TREE
		{
			public :
			bintree_node<key, T2> *Root;
			bintree_node<key, T2> *imtheEnd;
			int imroot;
			private:

			Compare cmp;

			public:
			typedef typename Allocator::template rebind<bintree_node<key, T2> >::other alloccc;
			typedef bintree_node<key, T2> treenode;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef T2 value_type;
			typedef key key_type;
			typedef pair<key, T2> value;
			typedef typename Allocator::pointer pointer;
			typedef Allocator allocator_type;
			typedef typename std::size_t size_type;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::Bidirectional_iterator<value, treenode, Compare> iterator;
			typedef ft::Bidirectional_iterator<const value, treenode, Compare> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			allocator_type x;

			size_type _size;
			private:
			alloccc c;

			public:
			AVL_TREE(treenode *node = NULL)
			{
				Root = node;
				//	alloccc c;
				_size = 0;
				imtheEnd = c.allocate(1);
				imtheEnd->parent = NULL;
				imtheEnd->left = NULL;

				Root = c.allocate(1);
				Root->parent = imtheEnd;
				Root->left = imtheEnd;
				Root->right = imtheEnd;
				Root->data = NULL;
				imtheEnd->left = NULL;
				imtheEnd->right = Root;
				imroot = 0;
			}
			AVL_TREE(AVL_TREE const &src)
			{
			}

			treenode *newnode(const ft::pair<key, T2> &p, treenode *parent, treenode *node, const allocator_type &alloc = allocator_type())
			{
				x = alloc;
				alloccc c;
				if (imroot == 0)
				{
					node->data  = x.allocate(1);
					x.construct(node->data, p);
					node->height = 1;
					imroot = 1;
					return node;
				}
				treenode *newno = c.allocate(1);
				newno->left = imtheEnd;
				newno->right = imtheEnd;
				newno->parent = parent;
				newno->data  = x.allocate(1);
				x.construct(newno->data, p);
				newno->height = 1;
				newno->inserted = true;
				return newno;
			}
			void free_tree1()
			{
				free_tree(Root);
				//imroot = 0;
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
				if (tmp1 != imtheEnd)
				{
					free_tree(tmp1);
				}
				if (tmp2 != imtheEnd)
				{
					free_tree(tmp2);
				}
				return;
			}
			treenode *searchforkey(const key_type &x, treenode *node) const
			{
				treenode *replace;
				int a = 0;
				int b = 0;
				replace = node;
				if(node->data != NULL)
					if (node->data->first == x)
						return replace;
				// if (replace->left != imtheEnd && replace-> right != imtheEnd)
				//{
				if (replace->left != imtheEnd && (cmp(x, replace->data->first)))
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
					// if(replace->right != imtheEnd)
				}
				//}
				// else
				//{
				//	if (replace != NULL)
				// replace = NULL;
				if (a == 0 && b == 0)
					replace = NULL;
				return replace;
			}

			treenode *lowkeyofroot(treenode *root1) const
			{
				treenode *replace = root1;
				// replace = root;
				if (replace->left != imtheEnd)
					if (!(cmp(replace->data->first, replace->left->data->first)))
					{
						replace = lowkeyofroot(replace->left);
					};
				if (replace->right != imtheEnd)
					if (!(cmp(replace->data->first, replace->right->data->first)))
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
						if (cmp(get_myPredecessor(replace->parent)->data->first, node->data->first))
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
				T2 c;
				p = ft::make_pair(x, c);
				thenode = NULL;
				if (Root != NULL)
					thenode = searchforkey(x, Root);
				if (thenode == NULL)
				
					{
					Root = insert_elements(Root, imtheEnd, p);
					imtheEnd->right = Root;
					}
				else
					return thenode->data->second;
				thenode = searchforkey(x, Root);
				return thenode->data->second;
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
				ft::pair<key, T2> val;
				T2 p;
				val = ft::make_pair(k, p);
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
				std::vector<key> myvector;
				while (first != last)
				{
					myvector.push_back(first->first);
					first++;
				}
				typename std::vector<key>::iterator op = myvector.begin();
				//iterator temp = first;
				//val = ft::make_pair(position->first, position->second);
				int i = 0;
				key c;
				while(i < myvector.size())
				{
					T2 p;
					//val = ft::make_pair(op[i], p);
					Root = deleteNode(Root, myvector[i]);
					c = myvector[i];
					//_size--;
					//	std::cout<<op[i]<<std::endl;
					i++;
					//std::cout<<"lllllllllllllllllllllllllll"<<std::endl;
					//first++;
				}
			}
			}
			// something not working here x
			treenode *insert_elements(treenode *node, treenode *parent, const ft::pair<key, T2> &p)
			{
				if ((node == NULL || node == imtheEnd) || imroot == 0)
				{
					_size++;
					return newnode(p, parent, node);
				}
				else if (node != imtheEnd && node != NULL)

				{
					//	//std::cout<<"||||"<<node->data->first<<std::endl;
					//std::cout << p.first << std::endl;

					if (node->data->first == p.first)
					{
						//node->data->second = p.second;
						node->inserted = false;
						return node;
					}
				}

				if (cmp(p.first, node->data->first))
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
					if (cmp(p.first,node->left->data->first))
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
					if (!cmp(p.first,node->right->data->first))
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
							std::cout << "parent : " << node->parent->data->first << std::endl;
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
						if(node->parent->data != NULL)
							std::cout << "parent : " << node->parent->data->first << std::endl;
					}
					std::cout << node->data->first << std::endl;

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



				// Find the node and delete it
				if (node == imtheEnd)
					return node;
				if (node->data->first == p)
				{
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
						//	node = imtheEnd;
							if (node->parent != imtheEnd && cmp(temp->data->first, node->parent->data->first))
								node->parent->left = imtheEnd;
							else
								node->parent->right = imtheEnd;
							c.deallocate(temp,1);
							node = imtheEnd;
							_size--;
						}
						else
						{
							treenode *tmp2 = node->parent;
							*node = *temp;
							node->parent = tmp2;
						//	temp->parent = node->parent;
					
							c.deallocate(temp,1);
							_size--;
						}
					}
					else
					{
						treenode *temp = nodeWithMimumValue(node->right);
						node->data = temp->data;
						//node->parent = temp->parent;
						node->right = deleteNode(node->right,
								temp->data->first);
					}
				}
				else if (cmp(p, node->data->first) )
					node->left = deleteNode(node->left, p);
				else
					node->right = deleteNode(node->right, p);
				// else
				// {
				// 	if ((node->left == imtheEnd) ||
				// 			(node->right == imtheEnd))
				// 	{
				// 		treenode *temp;
				// 		if (node->left != imtheEnd)
				// 		{
				// 			temp = node->left;
				// 		}
				// 		else
				// 			temp = node->right;
				// 		if (temp == imtheEnd)
				// 		{

				// 			temp = node;
				// 		//	node = imtheEnd;
				// 			if (node->parent != imtheEnd && cmp(temp->data->first, node->parent->data->first))
				// 				node->parent->left = imtheEnd;
				// 			else
				// 				node->parent->right = imtheEnd;
				// 			c.deallocate(temp,1);
				// 			node = imtheEnd;
				// 			_size--;
				// 		}
				// 		else
				// 		{
				// 			treenode *tmp2 = node->parent;
				// 			*node = *temp;
				// 			node->parent = tmp2;
				// 		//	temp->parent = node->parent;
					
				// 			c.deallocate(temp,1);
				// 			_size--;
				// 		}
				// 	}
				// 	else
				// 	{
				// 		treenode *temp = nodeWithMimumValue(node->right);
				// 		node->data = temp->data;
				// 		//node->parent = temp->parent;
				// 		node->right = deleteNode(node->right,
				// 				temp->data->first);
				// 	}
				// }
					 if (node == imtheEnd)
    					return node;
				












				// if (node->data->first == p) 
				// {
				// 	if ((node->left == imtheEnd) ||
				// 			(node->right == imtheEnd))
				// 	{
				// 		treenode *temp;
				// 		if (node->left != imtheEnd)
				// 		{
				// 			temp = node->left;
				// 		}
				// 		else
				// 			temp = node->right;
				// 		//treenode *temp = node->left ? node->left : node->right;
				// 		if (temp == imtheEnd)
				// 		{
				// 			temp = node;
				// 			//temp->parent = node->parent;
				// 			node = imtheEnd;
				// 			if (node->parent != imtheEnd && cmp(temp->data->first, node->parent->data->first))
				// 				node->parent->left = imtheEnd;
				// 			else
				// 				node->parent->right = imtheEnd;
				// 		}
				// 		else
				// 		{
				// 			temp->parent = node->parent; 
				// 			//if (node->parent != imtheEnd)
				// 			if (node->parent != imtheEnd && cmp(temp->data->first, node->parent->data->first))
				// 				node->parent->left = temp;
				// 			else
				// 				node->parent->right = temp;
				// 			temp->parent = node->parent;
				// 			*node = *temp;
				// 			node->left = imtheEnd;
				// 			node->right = imtheEnd;
				// 		}
				// 		c.deallocate(temp,1);
				// 		_size--;
				// 	}
				// 	else
				// 	{
				// 		treenode *temp = nodeWithMimumValue(node->right);
				// 		node->data = temp->data;
				// 		//node->parent = temp->parent;
				// 		node->right = deleteNode(node->right,
				// 				temp->data->first);
				// 	}
				// }
				// else
				// {
				// 	if (node == imtheEnd || node == NULL)
				// 		return node;
				// 	if (cmp(p, node->data->first) && node->left != imtheEnd &&  node->left != NULL)
				// 		node->left = deleteNode(node->left, p);
				// 	else 
				// 		node->right = deleteNode(node->right, p);

				// }

				// Update the balance factor of each node and
				// balance the tree
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
			~AVL_TREE()
			{
			}

			//	AVL_TREE &		operator=( AVL_TREE const & rhs );
			};
		}

#endif /* ******************************************************** AVL_TREE_H */
