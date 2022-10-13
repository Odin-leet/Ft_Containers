#ifndef BIDIRECTIONAL_ITERATOR_HPP 
#define BIDIRECTIONAL_ITERATOR_HPP
//#include "Avl_tree.hpp"
#include "iterator_base.hpp"
#include <iostream>


namespace ft{
	template <class T, class data, class Compare > 
		class Bidirectional_iterator : public ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> > 
	{
		public:

			typedef T iterator_type;
			//typedef Iterator<T> iterator;
			typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::value_type        value_type;
			typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::difference_type   difference_type;
			typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::pointer           pointer;
			typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::reference         reference;
			typedef typename ft::iterator_traits<ft::iterator_base<std::bidirectional_iterator_tag, T> >::iterator_category         iterator_category;
		private:
			data *node;
			data *root;
			data *end;
			pointer pair;
			Compare cmp;
			// hnaya 
			void print()
			{
				printTree(root, "",true);
			}
			void printTree( data *node, std::string indent, bool last) {
				//	bintree_node *node ;
				if (node != end) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}
					std::cout << node->data->first << std::endl;
					printTree(node->left, indent, false);
					printTree(node->right, indent, true);
				}
			}
			data *highkeyofroot(data *root1)
			{
				data* replace = root1;
				//replace = root;
				if (replace->left != end)
					if ((cmp(replace->data->first, replace->left->data->first)))
					{
						replace = highkeyofroot(replace->left);
					};
				if (replace->right != end)
					if ((cmp(replace->data->first, replace->right->data->first)))
					{
						replace = highkeyofroot(replace->right);
					};
				return replace;
			}
			data *lowkeyofroot(data *root1)
			{
				data* replace = root1;
				//replace = root;
				if (replace->left != end)
					if (!(cmp(replace->data->first, replace->left->data->first)))
					{
						replace = highkeyofroot(replace->left);
					};
				if (replace->right != end)
					if (!(cmp(replace->data->first, replace->right->data->first)))
					{
						replace = highkeyofroot(replace->right);
					};
				return replace;
			}

			void returningmyroot(data *myreplace)
			{
				//data *myreplace;
				data *replace2;
				//	print();
				if (myreplace->parent == NULL)
				{	
					end = myreplace;
					root = myreplace->right;
					return;
				}
				if (myreplace->parent->parent == NULL)
				{	
					end = myreplace->parent;
					root = myreplace;
					return;
				}
				end = NULL;
				int checker = 1;
				//	std::cout<<"im the root in after that place  in returning: "<<myreplace<<std::endl;
				// myreplace = node;
				while (myreplace->parent->parent != NULL)
				{
					//std::cout<<"im here "<<"\n";
					myreplace = myreplace->parent;

				}
				end = myreplace->parent;
				root = myreplace->parent->right;
				//std::cout<<"im the root in after that place  in returning: 1  "<<myreplace->right<<std::endl;

				//return (myreplace->right);
				//root->parent
			}
			data  *get_simplemyPredecessor(data *node)
			{
				//print();
				//printmyend(root);
				//	std::cout<<"|Root4 LEFT:|"<<root->left<<std::endl;
				//std::cout<<"|end 4:|"<<end<<std::endl;

				data * myreplace;
				//	data *replace2;
				if (node != end && node->left != end)
				{
					//node * myreplace;
					myreplace = node->left;
					while (myreplace->right != end  && myreplace->right != NULL)
					{
						myreplace = myreplace->right;
					}
					return (myreplace);
				}
				return node;
			}
			data  *get_myPredecessor(data *node)
			{
				//print();
				//printmyend(root);
				//		std::cout<<"|Root4 LEFT:|"<<root->left<<std::endl;
				//	std::cout<<"|end 4:|"<<end<<std::endl;

				data * myreplace;
				data *replace2;
				if (node != end && node->left != end)
				{
					//node * myreplace;
					myreplace = node->left;
					while (myreplace->right != end  && myreplace->right != NULL)
					{
						myreplace = myreplace->right;
					}
					return (myreplace);
				}
				else
				{
					myreplace = node;

					// if (replace2->parent == end)
					// 	return end;
					replace2 = myreplace->parent;


					while (replace2->left != end && myreplace->data->first == replace2->left->data->first && replace2 ->parent != NULL)
					{
						myreplace = replace2;
						replace2 = replace2->parent;
					}
					// if (replace2->right != myreplace)
					// {
					myreplace = replace2;
					return myreplace;
					// }
					// 	myreplace = node;
					// 	if( myreplace->parent != end)
					// {
					//  if(cmp((get_myPredecessor(myreplace->parent))->data->first, node->data->first))
					// 			return myreplace->parent;
					// else
					// {
					// 	while (myreplace->parent != end)
					// 	{
					// 			replace2 = get_simplemyPredecessor(myreplace->parent);
					// 			if (cmp(replace2->data->first, node->data->first))
					// 				return replace2;
					// 			myreplace = myreplace->parent;
					// 	}
					// }
					// 		// myreplace = myreplace->parent;
					// 	}
				}//else }
			// return NULL;
			return node;
	}
	//	}
	//the node lies ahead of given node
data  *get_simplemySuccessor(data *node)
{
	data *myreplace;

	if (node->right != end && node->right != end)
	{
		//	data * myreplace;
		myreplace = node->right;
		while (myreplace->left != end && myreplace->left != NULL)
		{
			myreplace = myreplace->left;
		}
		return (myreplace);
	}
	return node;
}
data  *get_mySuccessor(data *node)
{
	data *myreplace;
	data *replace2;
	data *replace3;
	if (node->right != end && node->right != end)
	{
		//	data * myreplace;
		myreplace = node->right;
		while (myreplace->left != end && myreplace->left != NULL)
		{
			myreplace = myreplace->left;
		}
		return (myreplace);
	}
	else
	{
		myreplace = node;

		if (myreplace->parent == end)
			return end;
		replace2 = myreplace->parent;

		while (myreplace == replace2 ->right && replace2 ->parent != NULL)
		{
			myreplace = replace2;
			replace2 = replace2->parent;
		}
		if (replace2->right != myreplace)
		{
			myreplace = replace2;
			return myreplace;
		}
		// 	myreplace = node;
		// 	if( myreplace->parent != end)
		// {
		// 	T op;
		//  if(!(cmp(((op = get_mySuccessor(myreplace->parent)->data)).first, node->data->first)) && op.first != node->data->first)
		// 			return myreplace->parent;
		// else
		// {
		// 	while (myreplace->parent != end)
		// 	{
		// 			replace2 = get_simplemySuccessor(myreplace->parent);
		// 			if (!cmp(replace2->data->first, node->data->first) && replace2->data->first != node->data->first)
		// 				return replace2;
		// 			myreplace = myreplace->parent;
		// 	}
		// }
		// 		// myreplace = myreplace->parent;
		// 	}
		// 	}//else }

}return end;
}
public : 



Bidirectional_iterator(data *lop = NULL)
{
	if (lop == NULL)
	{
		root = NULL;
		node = NULL;
		end = NULL;

	}
	else
	{
		node = lop;
		//en
		//	std::cout<<"im the root in after that place  in returning: 3 "<<node<<std::endl;

		//{
		//	returningmyroot();
		//if (root != NULL)

		returningmyroot(node);
		//print();		//		std::cout<<"im the root in after that place  in returning: 4 "<<root<<std::endl;

		//if (node != NULL && node != end)
		pair = node->data;
	}
	//else
	//{
	//							//			std::cout<<"im the root in after that place  in returning: 55"<<root<<std::endl;
	//
	//root = NULL;
	//end = NULL;
	//}
	}

	void printmyend(data *node1)
	{
		//		std::cout<<"|Root 3|"<<root<<std::endl;
		//		std::cout<<"|end  3|"<<end<<std::endl;
	}
	reference operator*() const {
		//	pair = node->data;

		return *(node->data);
	}
	data*  base() const { return node; }
	template<typename _iterator, typename Data1, typename Compare1>
		Bidirectional_iterator(const Bidirectional_iterator <_iterator, Data1, Compare1> & i ){

			node = i.get_node();
			//node->data = i.node->data;
			pair = node->data;
			root = i.get_root();
			if (root != NULL)
			{
				end = root->parent;
			}
		};

	Bidirectional_iterator &operator=(const Bidirectional_iterator &rhs)
	{
		node = rhs.node;
		node->data = rhs.node->data;
		pair = rhs.node->data;
		root = rhs.root;
		end = rhs.end;
		return *this;
	}
	Bidirectional_iterator &operator--()
	{

		if (node == end)
		{

			node = highkeyofroot(root);
		}
		else
		{
			node = get_myPredecessor(node);

		}
		return *this;
	}
	Bidirectional_iterator &operator++()
	{
		data *myreplace = node;
		if (myreplace == end)
		{
			//pair = node->data;
			return *this;
		}
		else
		{
			node = get_mySuccessor(node);
			pair = node->data;

		}
		return *this;
	}
	Bidirectional_iterator operator--(int)
	{
		data *myreplace = node;
			//if( node)
			if (node == end)
			{

				node = highkeyofroot(root);
			}
			else
				node = get_myPredecessor(node);
		//	pair = node->data;
		return Bidirectional_iterator(myreplace);
	}
	Bidirectional_iterator operator++(int)
	{
		data *myreplace = node;
		if (node == end)
		{

			return Bidirectional_iterator(myreplace);
		}
		else
			node = get_mySuccessor(node);
		//	pair = node->data;
		return Bidirectional_iterator(myreplace);
	}
	data *get_node() const{
		return node;
	}
	data *get_root()const
	{
		return root;
	}
	pointer operator->() const
	{
		return this->node->data;
	}

};

	template <class Iterator, class data, class Compare>
bool operator==(const Bidirectional_iterator<Iterator, data, Compare>& x, const Bidirectional_iterator<Iterator, data, Compare>& y)
{
	return (x.base() == y.base());
}
	template <class Iterator, class data, class Compare>
bool operator!=(const Bidirectional_iterator<Iterator, data, Compare>& x, const Bidirectional_iterator<Iterator, data, Compare>& y)
{
	return (x.base() != y.base());
}
}
#endif
