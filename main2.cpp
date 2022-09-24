# include "Bidirectional_iterator.hpp"
#include "Avl_tree.hpp"
# include <map>
# include<iostream>


int main()
{
    std::map<int, std::string> mymap;
    mymap[0] = "asdakdasdasda";
    mymap[1] = "123456789";
    mymap[2] = "sadasdasd";
    mymap[3] = "xzcxzcxzcxz";
    mymap[4] = "§ §da";
    mymap[5] = "eee";
    mymap[6] = "§xc";
    mymap[7] = "ffff";
    mymap[8] = "sasd";
    mymap[9] = "asdakdasdrrrrasda";
    mymap[10] = "vv";


   // mymap[10] = "sadsadasdasdasd";
    std::map<int, std::string>::iterator it = mymap.end();
    it--;
    std::cout<<mymap[10]<<std::endl;
    std::cout<<it->first<<std::endl;
   // it++;
   //ft::pair<int,int> allo;
   //ft::bintree_node<int, int> *node;
   //node = (ft::bintree_node<int, int> *)(malloc(sizeof (ft::bintree_node<int, int> *)));

   //allo = ft::make_pair(4,566);
   //node->data = allo;
   //ft::Bidirectional_iterator<ft::bintree_node<int,int> , ft::pair<int,int> > ittt;
    //ft::Bidirectional_iterator<ft::bintree_node<int,int> , ft::pair<int,int> > it1(node, node->data);
   // std::cout<<allo.
    
    //std::cout<<it->second<<std::endl;
}