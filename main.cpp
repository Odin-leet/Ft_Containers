#include "Vector.hpp"
#include <vector>
//#include "Iterator.hpp"
 #define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

//#include "reverse_iterator.hpp"
int main()
{
       std::string str, ft_str;
         /*
          * var to store the size and the capacity
          */
         ft::Vector<std::string>::iterator ft_it;
        std::vector<std::string>::iterator it;
         ft::Vector<std::string>::size_type s, ft_s;
         ft::Vector<std::string>::size_type c, ft_c;
         /*
          * bool to store the comparison
          */
         bool cond;
         // insert at the begin
     std::vector<std::string> v(20, "string");
             ft::Vector<std::string> ft_v(20, "string");
             ft::Vector<std::string>::iterator valid_it;
             v.reserve(30);
             ft_v.reserve(30);
             valid_it = ft_v.begin();
             it = v.insert(v.begin() + 10, "hello");
             ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
             ft_it->length();
             str.clear();
             ft_str.clear();
             s = v.size();
             ft_s = ft_v.size();
             c = v.capacity();
             ft_c = ft_v.capacity();
             for (size_t i = 0; i < v.size(); ++i)
                 str += v[i];
             for (size_t i = 0; i < ft_v.size(); ++i)
                 ft_str += ft_v[i];
             cond = (  (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
     
}
//     third.push_back(0);
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
