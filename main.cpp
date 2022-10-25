//#include "Vector.hpp"
#include "Avl_tree.hpp"
#include "map.hpp"
#include <map>
#include <utility>
#include <string>
#include <ostream>

 //#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

//#include "reverse_iterator.hpp"
int main()
{

        //           std::map<int, std::string> m1;
        // ft::Map<int, std::string> ft_m1;

        // for (size_t i = 0; i < 10; i++)
        // {
        //     m1.insert(std::make_pair(i, "string2"));
        //     ft_m1.insert(ft::make_pair(i, "string2"));
        // }

        // std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        // ft::Map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        // /*-----------------------------------------------------*/
        // /*------------------ ft::Maps ---------------------*/
        // /*----------------------------------------------------*/
        // /*------------------ strings to store the results ----*/
        // std::string res, ft_res, c_res, c_ft_res;
        // ft::Map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin();
        //  rit != ft_m2.rend();
        //   ++rit;


  time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::Map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            { 
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }
            
           // start = get_time();
            m1.erase(m1.begin(), m1.end());
          //  end = get_time();
          //  diff = end - start;
          //  diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::Maps ---------------------*/
           // ualarm(diff * 1e3, 0);
            ft_m1.erase(ft_m1.begin(), ft_m1.end());

            std::cout<<"allo im here "<<std::endl;
         //   ualarm(0, 0);
            /*------------------------------------------------
            // std::map<int, std::string> m;
            // ft::Map<int, std::string> ft_m;
            // for (size_t i = 0; i < 25; ++i)
            // {
            //     m.insert(std::make_pair(i, "value"));
            //     ft_m.insert(ft::make_pair(i, "value"));
            // }
            // ft::Map<int , std::string>::const_reverse_iterator cit = ft_m.rbegin();
            // ft::Map<int , std::string>::const_reverse_iterator op = cit;
         // //    ft_m.printmymap();
        //         ft::Map<int, std::string>::iterator ft_it = --ft_m.end();
        //     for (; ft_it != ft_m.begin(); --ft_it)
        //         {
        //        std::cout<<ft_it->first<<std::endl;
        //            std::cout<<ft_m.begin()->first<<std::endl;

        //         }

// //              
//             ft::pair<char,int> ballo = ft::make_pair('c',222222);
//             ft::pair<char,int> ballo2 = ft::make_pair('d',222222);
//             ft::pair<char,int> ballo3 = ft::make_pair('f',222222);
//             ft::pair<char,int> ballo4 = ft::make_pair('z',222222);
//             ft::pair<char,int> ballo5 = ft::make_pair('a',222222);
//             ft::pair<char,int> ballo6 = ft::make_pair('t',222222);
//             ft::pair<char,int> ballo8 = ft::make_pair('r',222222);
//             ft::pair<char,int> ballo7 = ft::make_pair('m',222222);
//             ft::pair<char,int> ballo9 = ft::make_pair('w',222222);
//             ft::pair<const char,int> ballo10 = ft::make_pair('b',222222);

        //     ft::pair<int,int> ballo = ft::make_pair(1,222222);
        //     ft::pair<int,int> ballo4 = ft::make_pair(5,222222);
        //     ft::pair<int,int> ballo5 = ft::make_pair(77,222222);
        //     ft::pair<int,int> ballo6 = ft::make_pair(88,222222);
        //     ft::pair<int,int> ballo8 = ft::make_pair(3,222222);
        //     ft::pair<int,int> ballo2 = ft::make_pair(55,222222);
        //     ft::pair<int,int> ballo7 = ft::make_pair(11,222222);
        //     ft::pair<int,int> ballo9 = ft::make_pair(17,222222);
        //     ft::pair<const int,int> ballo10 = ft::make_pair(900,22222);
            
        //     ft::pair<int,int> allo = ft::make_pair(68,222222);
        //     ft::pair<int,int> allo2 = ft::make_pair(55,222222);
        //     ft::pair<int,int> allo3 = ft::make_pair(66,222222);
        //     ft::pair<int,int> allo4 = ft::make_pair(22,222222);
        //     ft::pair<int,int> allo5 = ft::make_pair(77,222222);
        //     ft::pair<int,int> allo6 = ft::make_pair(88,222222);
        //     ft::pair<int,int> allo8 = ft::make_pair(90,222222);
        //     ft::pair<int,int> allo7 = ft::make_pair(11,222222);
        //     ft::pair<int,int> allo9 = ft::make_pair(10,222222);
        //     ft::pair<const int,int> allo10 = ft::make_pair(900,222222);
        //                 ft::pair<const int,int> allo11 = ft::make_pair(900,9966);

        // //    ft::pair<int,int> allo = ft::make_pair(23,222222);
        //     ft::bintree_node<int, int> *root = NULL;
        //     ft::map<int, int> oc1;
        //                 ft::map<int,int> oj1;
        //    oj1.insert1(allo);
        //    oj1.insert1(allo8);
        //   // oj1.insert1(allo3);
        //    oj1.insert1(allo4);
        //    oj1.insert1(allo5);
        //    oj1.insert1(allo6);
        //    oj1.insert1(allo7);
        //    oj1.insert1(allo2);
        //    oj1.insert1(allo9);
        //    oj1.insert1(allo);
        //    oj1.insert1(allo8);
        //   //  oc1.insert1(ballo3);
        //     oc1.insert1(ballo4);
        //     oc1.insert1(ballo5);
        //     oc1.insert1(ballo6);
        //     oc1.insert1(ballo7);
        //     oc1.insert1(ballo2);
        //     oc1.insert1(ballo9);

        //     //ft::map<int,int>::iterator ocbegin = oc1.begin();
        //     //ft::map<int,int>::iterator ocend = oc1.end();

        //                   oc1.printmymap();
        //                   std::cout<<"this is my shit "<<std::endl;
        //                   oc1.swap(oj1);
        //                   oc1.printmymap();
        //                //   oc1.clear();
        //                                             oc1.printmymap();
        //                                            // oc1.insert(allo9);
        //       std::cout<<oc1.find(11)->first<<std::endl;


            //std::cout<<ocbegin->first<<std::endl;
             //ocbegin++;
            //ocbegin++;

                      //  std::cout<<ocbegin->first<<std::endl;
                        //            oc1.erase(oc1.begin(), ocbegin);

       //       oc1.insert1(allo3);
         //                   oc1.insert1(allo);

             //                       std::cout<<oc1.erase(55)<<std::endl;

            //oc1.printmymap();          //  oj1.insert(ocbegin, ocend);
           // oj1.printmymap();

          //   ft::AVL_TREE<int, int>  allo1(root);
          //   ft::bintree_node<int, int> *root1 = NULL;
          //   ft::bintree_node<int, int> *root2 = NULL;
          //   ft::AVL_TREE<int,int>::iterator it;
          //   ft::AVL_TREE<int,int>::iterator itb;
          //   ft::map<int, int> op;
          //   op.insert1(allo);
          //   op.insert1(allo2);
          //   op.insert1(allo3);
          //   op.insert1(allo4);
          //   op.insert1(allo5);
          //   op.insert1(allo6);
          //   op.insert1(allo7);
          //   op.insert1(allo8);
          //   op.insert1(allo9);
          // //   std::cout<<"im heeeere al9laoui "<<std::endl;
          //    op.printmymap();
          // //   ft::map<int,int> op1;
          // //  op1 = op;
          // //  op1.printmymap();
          // // ft::pair<ft::map<int,int>::iterator, bool> p;
          // // p = op1.insert(allo10);
          // // ft::map<int,int>::iterator op2;
          // // op2 = p.first;
          //            op1.printmymap();
          // op1.insert(op2, allo11);
          // std::cout<<p.second<<std::endl;

          //while (1);
           // it = allo1.end();
            // allo1.insert(allo);
            // allo1.insert(allo2);
            // allo1.insert(allo3);
            // allo1.insert(allo4);
            // allo1.insert(allo5);
            // allo1.insert(allo6);
            // allo1.insert(allo7);
            // allo1.insert(allo8);
            // allo1.insert(allo9);
            // allo1[100]= 700;
            //         allo1.print();
            //         std::cout<<"µµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµµ*"<<std::endl;
            //         allo1.free_tree1();

            //                             allo1.print();

      //       it = allo1.end();
      //       it--;
      //               std::cout<<it->second<<std::endl;

      //       it--;
      //                           std::cout<<it->first<<std::endl;

      //       it--;
      //                           std::cout<<it->first<<std::endl;

      //       it--;
      //                           std::cout<<it->first<<std::endl;

      //       it++;
      //                std::cout<<it->first<<std::endl;

      //                  it++;
      //                std::cout<<it->first<<std::endl;
      //                std::cout<<"|"<<allo1.size()<<std::endl;
      //  //  std::cout<<itb->first<<std::endl;
       //    itb = allo1.begin();
         //  allo1.print();
       //   std::cout<<it->first<<std::endl;
       //   std::cout<<itb->first<<std::endl;
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
