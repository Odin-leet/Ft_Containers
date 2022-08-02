#include "Vector.hpp"
#include <vector>
#include "Iterator.hpp"

int main()
{
   // ft::Vector<std::string> a(5, "WEWEWEWEWE");
    //std::vector<std::string> a(5,"WEWEWEWEWE");
    //a.pop_back();
    //std::cout<<a.max_size()<<std::endl;
    std::cout<<"asdasdasdas"<<std::endl;
    ft::Vector<int> a(5,77);
    a.reserve(6);
    a.push_back(9);
    a.push_back(10);

    

   // ft::Vector<std::string>::iterator  it(a.begin()) ;
    //it += 2;
    ft::Vector<int>::iterator pos;
    pos = a.begin();
    pos += 5;
      for (ft::Vector<int>::iterator  it(a.begin()) ; it != a.end(); it += 1)
        {
    //       std::cout<<i<<std::endl;
    //       std::cout<<a[i]<<std::endl;
    //       //a.at(i) = i;
    //       std::cout<<a.at(i)<<std::endl;
        std::cout<<*it<<std::endl;
       // i++;
        }
    a.erase(pos);
          for (ft::Vector<int>::iterator  it(a.begin()) ; it != a.end(); it += 1)
        {
    //       std::cout<<i<<std::endl;
    //       std::cout<<a[i]<<std::endl;
    //       //a.at(i) = i;
    //       std::cout<<a.at(i)<<std::endl;
        std::cout<<*it<<std::endl;
       // i++;
        }
    int i = 0;
    for (ft::Vector<int>::iterator  it(a.begin()) ; it != a.end(); it += 1)
        {
    //       std::cout<<i<<std::endl;
    //       std::cout<<a[i]<<std::endl;
    //       //a.at(i) = i;
    //       std::cout<<a.at(i)<<std::endl;
        std::cout<<*it<<std::endl;
        i++;
        }
     //  std::cout<<"a.back() = "<< a.back()<<std::endl;
     //  std::cout<<"a.front() = "<< a.front()<<std::endl;

     //  a.back() -= a.front();
     //  std::cout<<"a.back() = "<< a.back()<<std::endl;
     //  std::cout<<"a.front() = "<< a.front()<<std::endl;

}
