#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP
//#include "map.hpp"
# include <iostream>
# include <string>
#include "Pair.hpp"
#include "Bidirectional_iterator.hpp"
template <class Type> struct rebind {
	typedef std::allocator<Type> other;
};
namespace ft{




	template<class key, class T2>
		struct bintree_node{
			bintree_node *left;
			bintree_node *right;
			bintree_node *parent;
			pair<key,T2> data;
			int height;

		} ;
	template <class key, class T2 ,class Compare = std::less<key> ,    class Allocator = std::allocator<pair<key, T2> > >
		class AVL_TREE
		{
			private:
				bintree_node<key, T2> *Root;
				bintree_node<key, T2> *imtheEnd;
				int imroot;
				Compare cmp;
			public:
				typedef typename Allocator::template rebind< bintree_node<key, T2> >::other alloccc;
				typedef  bintree_node<key, T2>          bintree_node;
				// typedef	AVL_TREE<key, T2> 				tree;
				typedef typename Allocator::reference			reference;	
				typedef typename Allocator::const_reference 	const_reference;
				typedef T2										value_type;
				typedef pair<key,T2>							value;
				typedef typename Allocator::pointer				pointer;
				typedef Allocator								allocator_type;
			//	typedef typename Allocator::const_pointer		const_pointer;
				typedef typename Allocator::const_pointer		const_pointer;
    			typedef ft::Bidirectional_iterator<value, bintree_node, Compare> 	iterator;
				allocator_type x;

				AVL_TREE(bintree_node *node = NULL)
				{
					Root = node;
				alloccc c;
					imtheEnd = c.allocate(1);
					imtheEnd->parent = NULL;
					imtheEnd->left = NULL;

					Root = c.allocate(1);
					Root->parent = imtheEnd;
					Root->left = imtheEnd;
					Root->right = imtheEnd;
					imtheEnd->left = NULL;
					imtheEnd->right = Root;
					std::cout<<"| 1.the end | "<<&imtheEnd<<"|"<<std::endl;
					std::cout<<"| 1.Root    | "<<&Root<<"|"<<std::endl;

					//Root = imtheEndptr;
					imroot = 0;

				}
				AVL_TREE( AVL_TREE const & src )
				{

				}

				bintree_node *newnode(ft::pair <key, T2> &p,bintree_node * parent, bintree_node *node, const allocator_type& alloc = allocator_type())
				{
					x = alloc;
					alloccc c;
					if (imroot == 0)
					{
						node->data = p;
						node->height = 1;
						imroot = 1;
						return node;
					}
					bintree_node *newno = c.allocate(1) ;
					newno->left = imtheEnd;
					newno->right = imtheEnd;
					newno->parent= parent;
					newno->data = p;
					newno->height = 1;
					return newno;
				}
				bintree_node *lowkeyofroot(bintree_node *root1)
				{
					bintree_node* replace = root1;
					//replace = root;
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
				//the node lies behind of given node
				bintree_node  *get_myPredecessor(bintree_node *node)
				{
					bintree_node * replace;
						if (node->left != imtheEnd)
						{
							//bintree_node * replace;
							replace = node->left;
							while (replace->right != imtheEnd  && replace->right != NULL)
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
							//else 
								return NULL;
						}
						return imtheEnd;
				}
				//the node lies ahead of given node
					bintree_node  *get_mySuccessor(bintree_node *node)
				{
						if (node->right != imtheEnd)
						{
							bintree_node * replace;
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
				bintree_node  *rightRotate(bintree_node *y) {
					bintree_node *x = y->left;
					bintree_node *T3 = x->right;
					bintree_node *parentrep = y->parent;

					y->parent = x;
					x->parent = parentrep;
					x->right = y;
					y->left = T3;
					y->height = max(height(y->left),
							height(y->right)) +
						1;
					x->height = max(height(x->left),
							height(x->right)) +
						1;
					return x;
				}

				// Rotate left
				bintree_node *leftRotate(bintree_node *x) {
					bintree_node *y = x->right;
					bintree_node *T3 = y->left;
					bintree_node *parentrep = x->parent;
					y->parent = parentrep;
					x->parent = y;
					y->left = x;
					x->right = T3;
					x->height = max(height(x->left),
							height(x->right)) +
						1;
					y->height = max(height(y->left),
							height(y->right)) +
						1;
					return y;
				}
				int height(bintree_node *N) {
					if (N == NULL || N == imtheEnd)
						return 0;
					return N->height;
				}
				int getBalanceFactor(bintree_node *N) {
					if (N == imtheEnd)
						return 0;
					return height(N->left) -
						height(N->right);
				}


				int max(int a, int b) {
					return (a > b) ? a : b;
				}
				bintree_node *nodeWithMimumValue(bintree_node *node) {
					bintree_node *current = node;
					while (current->left != imtheEnd)
						current = current->left;
					return current;
				}
				iterator end()
				{
					return iterator(imtheEnd);
				}
				iterator begin()
				{
					return iterator(lowkeyofroot(Root));
				}
				// pair *getnextnode(pair)
				void			insert(ft::pair <key, T2> &p)
				{
					//std::cout<<"im the root in this place : "<<Root<<std::endl;

					Root = insert_elements(Root, imtheEnd,p);
					//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
					imtheEnd->right = Root;
					iterator it(Root);
				//	std::cout<<"im the root in after that other place : "<<Root<<std::endl;
					it.printmyend(Root);
				//	std::cout<<"im the root in after that place : "<<Root<<std::endl;
				}
//something not working here x
				bintree_node * insert_elements( bintree_node *node,bintree_node *parent,ft::pair <key, T2> &p)
				{
					if ((node == NULL || node == imtheEnd) || imroot == 0 )
					{
						return newnode(p, parent, node);
					}
					else if (node != imtheEnd && node != NULL)

					{
					//	//std::cout<<"||||"<<node->data.first<<std::endl;
						std::cout<<p.first<<std::endl;

						if (node->data.first == p.first)
						{
							return node;
						}

					}

				
					if (cmp(p.first , node->data.first))
					{
						node->left = insert_elements(node->left, node, p );
					}
					else
					{
						node->right = insert_elements(node->right, node, p);
					}
					node->height = 1 + max(height(node->left),
							height(node->right));
					int balanceFactor = getBalanceFactor(node);
					if (balanceFactor > 1) {
						if (getBalanceFactor(node->left) >= 0) {
							return rightRotate(node);
						} else {
							node->left = leftRotate(node->left);
							return rightRotate(node);
						}
					}
					if (balanceFactor < -1) {
						if (getBalanceFactor(node->right) <= 0) {
							return leftRotate(node);
						} else {
							node->right = rightRotate(node->right);
							return leftRotate(node);
						}
					}
					return (node);

				}
				void print()
				{
					printTree(Root, "",true);
				}
				void printTree( bintree_node *node, std::string indent, bool last) {
				//	bintree_node *node ;
					if (node != imtheEnd) {
						std::cout << indent;
						if (last) {
							std::cout << "R----";
							indent += "   ";
						} else {
							std::cout << "L----";
							indent += "|  ";
						}
						std::cout << node->data.first << std::endl;
						std::cout << "parent : "<<node->parent->data.first << std::endl;
						printTree(node->left, indent, false);
						printTree(node->right, indent, true);
					}
				}

				//delete node 
				bintree_node *deleteNode(bintree_node *node, ft::pair <key, T2> &p) {
					// Find the node and delete it
					if (node == imtheEnd)
						return node;
					if (cmp (p.first , node->data.first))
						node->left = deleteNode(node->left, p);
					else if (cmp (p.first , node->data.first))
						node->right = deleteNode(node->right, p);
					else {
						if ((node->left == imtheEnd) ||
								(node->right == imtheEnd)) {
							bintree_node *temp = node->left ? node->left : node->right;
							if (temp == imtheEnd) {
								temp = node;
								node = imtheEnd;
							} else
								*node = *temp;
							free(temp);
						} else {
							bintree_node *temp = nodeWithMimumValue(node->right);
							node->data = temp->data;
							node->right = deleteNode(node->right,
									temp->data);
						}
					}

					if (node == imtheEnd)
						return node;

					// Update the balance factor of each node and
					// balance the tree
					node->height = 1 + max(height(node->left),
							height(node->right));
					int balanceFactor = getBalanceFactor(node);
					if (balanceFactor > 1) {
						if (getBalanceFactor(node->left) >= 0) {
							return rightRotate(node);
						} else {
							node->left = leftRotate(node->left);
							return rightRotate(node);
						}
					}
					if (balanceFactor < -1) {
						if (getBalanceFactor(node->right) <= 0) {
							return leftRotate(node);
						} else {
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
