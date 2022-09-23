//#include "Vector.hpp"
#include <vector>
#include "Avl_tree.hpp"
#include "map.hpp"

 //#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

//#include "reverse_iterator.hpp"
int main()
{
//              
            ft::pair<int,int> allo = ft::make_pair(23,222222);
            ft::pair<int,int> allo2 = ft::make_pair(55,222222);
            ft::pair<int,int> allo3 = ft::make_pair(66,222222);
            ft::pair<int,int> allo4 = ft::make_pair(22,222222);
            ft::pair<int,int> allo5 = ft::make_pair(77,222222);
            ft::pair<int,int> allo6 = ft::make_pair(88,222222);
            ft::pair<int,int> allo8 = ft::make_pair(90,222222);
            ft::pair<int,int> allo7 = ft::make_pair(11,222222);
            ft::pair<int,int> allo9 = ft::make_pair(10,222222);
            ft::pair<int,int> allo10 = ft::make_pair(22,222222);
        //    ft::pair<int,int> allo = ft::make_pair(23,222222);
            ft::bintree_node<int, int> *root = NULL;
            ft::AVL_TREE<int, int>  allo1(root);
            ft::bintree_node<int, int> *root1 = NULL;
            ft::bintree_node<int, int> *root2 = NULL;

            allo1.insert(allo);
            allo1.insert(allo2);
            allo1.insert(allo3);
            allo1.insert(allo4);
            allo1.insert(allo5);
            allo1.insert(allo6);
            allo1.insert(allo7);
            allo1.insert(allo8);
            allo1.insert(allo9);
            allo1.print();
           // ft::AVL_Tallo1.insert(allo);REE<int, int>::iterator it(root);
           // it.printmyend(root);
          //root =  allo1.insert_elements(root,NULL, allo2);
          //root =  allo1.insert_elements(root,NULL, allo3);
          //root =  allo1.insert_elements(root,NULL, allo4);
          //root =  allo1.insert_elements(root,NULL, allo5);
          //root =  allo1.insert_elements(root,NULL, allo6);
          //root =  allo1.insert_elements(root,NULL, allo7);
          //root =  allo1.insert_elements(root,NULL, allo8);
          //root =  allo1.insert_elements(root,NULL, allo9);
          //root =  allo1.insert_elements(root,NULL, allo10);
          // root = allo1.deleteNode(root,allo7);

        //  allo1.printTree(root, "",true);
        // root1 =  allo1.get_myPredecessor(root);
        // root2 =  allo1.get_mySuccessor(root);
        //             allo1.printTree(root1, "",true);
        //  allo1.printTree(root2, "",true);
        //  ft::AVL_TREE<int, int>::iterator t(root1);
        //  std::cout << (*t).first << std::endl;
//       std::string str, ft_str;
//       /*
//        * var to store the size and the capacity
//        */
//       ft::Vector<std::string>::size_type s, ft_s;
//       ft::Vector<std::string>::size_type c, ft_c;
//       ft::Vector<std::string>::iterator b1, b2;
//       /*
//        * bool to store the comparison
//        */
//       bool cond;
//       /*---------------------------------- test 1: equal size vectors ----------------------*/
//       {
//           std::vector<std::string> v(200, "hello");
//           std::vector<std::string> v1(200, "string");
//           ft::Vector<std::string> ft_v(200, "hello");
//           ft::Vector<std::string> ft_v1(200, "string");
//           b1 = ft_v.begin();
//           b2 = ft_v1.begin();
//           swap(v, v1);
//           swap(ft_v, ft_v1);
//           s = v.size();
//           ft_s = ft_v.size();
//           c = v.capacity();
//           ft_c = ft_v.capacity();
//           for (size_t i = 0; i < v.size(); ++i)
//               str += v[i];
//           for (size_t i = 0; i < ft_v.size(); ++i)
//               ft_str += ft_v[i];
//           cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
//           cond = (cond && ((&*b2) == (&(*ft_v.begin()))));
//           cond = (cond && ((&*b1) == (&(*ft_v1.begin()))));
      }
//
///     third.push_back(0);
//   third.push_back(0);
//   std::vector<std::string> apex;
//     std::vector<int> sfoc;
  
//   apex.push_back("alllloooooooooo  oooo ");
//     apex.push_back("alllloooooooooo  oooo ");
//   apex.push_back("alllloooooooooo  oooo ");
//   apex.push_back("alllloooooooooo  oooo ");
//   apex.push_back("alllloooooooooo  oooo ");
//   apex.push_back("alllloooooooooo  oooo ");
// //  sfoc.insert(sfoc.begin(),apex.begin(), apex.end());

// ft::Vector<std::string> allop(apex.begin(), apex.end());
//   ft::Vector<int>::iterator op = second.begin();
//   ft::Vector<int>::reverse_iterator op1(second.end());
//   //ft::Vector<int>::reverse_iterator it;      
//     ft::Vector<int>::const_iterator c_it(second.begin());
//    std::cout<<*c_it<<std::endl;
//      ft::Vector<int>::iterator j_it(op);
//      ft::Vector<int> allo;
//      allo.insert(allo.begin(),third.begin(), third.end());
//      for (ft::Vector<std::string>::iterator it = allop.begin(); it != allop.end(); it += 1)
//      {
//       std::cout<<*it<<std::endl;
//      }
//    // c_it = second.begin();
//     c_it+= 1;

 // std::vector<int> first (4,50);     
 // std::vector<int>::iterator op = first.begin();
 // std::vector<int>::reverse_iterator it;      
 // std::vector<int>::const_iterator c_it(first.cbegin());
 // std::cout<<*c_it<<std::endl;
 // std::vector<int>::iterator j_it(op);
 //  // c_it = second.begin();
 //   c_it+= 1;
// ft::Vector<int> third (second.begin(),second.end()); 
//
//
//  ft::Vector<int> alo;
//  alo.assign(6,60);
//animal *c = new cat();
//  alo.swap(second);
// for (ft::Vector<int>::iterator it = alo.begin() ; it != alo.end(); it += 1)
// {
//  std::cout<<*it<<std::endl;
// }
// alo.clear();
// std::cout<<"allo i m here "<<std::endl;
//   for (ft::Vector<int>::iterator it = alo.begin() ; it != alo.end(); it += 1)
// {
//  std::cout<<*it<<std::endl;
// }
   // ft::Vector<std::string> a(5, "WEWEWEWEWE");
    //std::vector<std::string> a(5,"WEWEWEWEWE");
    //a.pop_back();
    //std::cout<<a.max_size()<<std::endl;
 //   std::cout<<"asdasdasdas"<<std::endl;
 //   ft::Vector<int> a(5,77);
 //   a.reserve(6);
 //   a.push_back(9);
 //   a.push_back(10);
 //   ft::Vector<int> bd
 //   b.push_back(80);
 //  b.push_back(90);
 //   b.push_back(50);
 //   b.push_back(90);
 //   b.push_back(30);
//
 //   ft::Vector<int>::iterator itt = a.begin();
 //   itt += 3;
////  //std::cout<< l<<std::endl;
 //a.insert(itt, b.begin(),b.end());

//?///////////////////////////////////////////////

// std::cout<<"asdasdasdas"<<std::endl;
//  std::vector<int> a(5,77);
//   a.reserve(6);
//   a.push_back(9);
//   a.push_back(10);
//   std::vector<int> b;
//   b.push_back(80);
//  b.push_back(90);
//   b.push_back(50);
//   b.push_back(90);
//   b.push_back(30);
//
//   std::vector<int>::iterator itt = a.begin();
//   itt += 3;
///  //std::cout<< l<<std::endl;
//.assign(b.begin(), b.end()- 1);
////a.insert(itt, b.begin(),b.end());
///  int *C;
///  int *d;
//  // std::cout<<C -d<<std::endl;
//  // ft::Vector<std::string>::iterator  it(a.begin()) ;
//   //it += 2;
//// ft::Vector<int>::iterator pos;
////     ft::Vector<int>::iterator pos2;
////     pos2 = a.end();
////     //pos2 += 5;
//
//// pos = a.begin();
//// pos += 3;
//or (std::vector<int>::iterator  it(a.begin()) ; it != a.end(); it+=1)
//std::cout<<*it<<std::endl;
 // std::cout<<"||||||||||||||||||||||||||||||||||"<<std::endl;
 //       for (ft::Vector<int>::iterator  it(a.begin()) ; it != a.end(); it++)
 //     {
 // //       std::cout<<i<<std::endl;
 // //       std::cout<<a[i]<<std::endl;
 // //       //a.at(i) = i;
 // //       std::cout<<a.at(i)<<std::endl;
 //     std::cout<<*it<<std::endl;
 //    // i++;
 //     }
 // int i = 0;
 //     std::cout<<"||||||||||||||||||||||||||||||||||"<<std::endl;

 // for (ft::Vector<int>::iterator  it(a.begin()) ; it != a.end(); it++)
 //     {
 // //       std::cout<<i<<std::endl;
 // //       std::cout<<a[i]<<std::endl;
 // //       //a.at(i) = i;
 // //       std::cout<<a.at(i)<<std::endl;
 //     std::cout<<*it<<std::endl;
 //     i++;
 //     }
     //  std::cout<<"a.back() = "<< a.back()<<std::endl;
     //  std::cout<<"a.front() = "<< a.front()<<std::endl;

     //  a.back() -= a.front();
     //  std::cout<<"a.back() = "<< a.back()<<std::endl;
     //  std::cout<<"a.front() = "<< a.front()<<std::endl;

//}
