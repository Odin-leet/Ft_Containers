#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP
//#include "map.hpp"
# include <iostream>
# include <string>
#include "Pair.hpp"
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
				int imroot;
				Compare cmp;
			public:
				typedef typename Allocator::template rebind< bintree_node<key, T2> >::other alloccc;
				typedef  bintree_node<key, T2>          bintree_node;
				typedef typename Allocator::reference			reference;	
				typedef typename Allocator::const_reference 	const_reference;
				typedef T2										value_type;
				typedef typename Allocator::pointer				pointer;
				typedef Allocator								allocator_type;
			//	typedef typename Allocator::const_pointer		const_pointer;
				typedef typename Allocator::const_pointer		const_pointer;
    			//typedef ft::Bidirectional_iterator<const value_type> const_iterator;
				allocator_type x;

				AVL_TREE()
				{
					Root = nullptr;
					imroot = 0;

				}
				AVL_TREE( AVL_TREE const & src )
				{

				}

				bintree_node *newnode(ft::pair <key, T2> &p,bintree_node * parent, const allocator_type& alloc = allocator_type())
				{
					x = alloc;
					alloccc c;
					bintree_node *newno = c.allocate(1) ;
					newno->left = NULL;
					newno->right = NULL;
					newno->parent= parent;
					newno->data = p;
					newno->height = 1;
					return newno;
				}
				//the node lies behind of given node
				bintree_node  *get_myPredecessor(bintree_node *node)
				{
						if (node->left != NULL)
						{
							bintree_node * replace;
							replace = node->left;
							while (replace->right != NULL)
							{
								replace = replace->right;
							}
							return (replace);
						}
						return NULL;
				}
				//the node lies ahead of given node
					bintree_node  *get_mySuccessor(bintree_node *node)
				{
						if (node->right != NULL)
						{
							bintree_node * replace;
							replace = node->right;
							while (replace->left != NULL)
							{
								replace = replace->left;
							}
							return (replace);
						}
						return NULL;
				}
				// Rotate right
				bintree_node  *rightRotate(bintree_node *y) {
					bintree_node *x = y->left;
					bintree_node *T3 = x->right;
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
					if (N == NULL)
						return 0;
					return N->height;
				}
				int getBalanceFactor(bintree_node *N) {
					if (N == NULL)
						return 0;
					return height(N->left) -
						height(N->right);
				}


				int max(int a, int b) {
					return (a > b) ? a : b;
				}
				bintree_node *nodeWithMimumValue(bintree_node *node) {
					bintree_node *current = node;
					while (current->left != NULL)
						current = current->left;
					return current;
				}
				bintree_node * insert_elements( bintree_node *node,bintree_node *parent,ft::pair <key, T2> &p)
				{
					if (node != NULL)
						if (node->data.first == p.first)
						{
							return node;
						}

					if (node   == NULL )
					{
						return  newnode(p, parent);
					}
					if (cmp(p.first , node->data.first))
					{
						node->left = insert_elements(node->left, parent, p );
					}
					else
					{
						node->right = insert_elements(node->right, parent, p);
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
				void printTree(bintree_node *node, std::string indent, bool last) {
					if (node != nullptr) {
						std::cout << indent;
						if (last) {
							std::cout << "R----";
							indent += "   ";
						} else {
							std::cout << "L----";
							indent += "|  ";
						}
						std::cout << node->data.first << std::endl;
						printTree(node->left, indent, false);
						printTree(node->right, indent, true);
					}
				}

				//delete node 
				bintree_node *deleteNode(bintree_node *node, ft::pair <key, T2> &p) {
					// Find the node and delete it
					if (node == NULL)
						return node;
					if (cmp (p.first , node->data.first))
						node->left = deleteNode(node->left, p);
					else if (cmp (p.first , node->data.first))
						node->right = deleteNode(node->right, p);
					else {
						if ((node->left == NULL) ||
								(node->right == NULL)) {
							bintree_node *temp = node->left ? node->left : node->right;
							if (temp == NULL) {
								temp = node;
								node = NULL;
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

					if (node == NULL)
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
