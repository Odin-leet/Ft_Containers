#include "Vector.hpp"
#include <vector>

int main()
{
   // ft::Vector<std::string> a(5, "WEWEWEWEWE");
    std::vector<std::string> a(5,"WEWEWEWEWE");
    a.pop_back();
    std::cout<<a.max_size()<<std::endl;
    std::cout<<"asdasdasdas"<<std::endl;
}