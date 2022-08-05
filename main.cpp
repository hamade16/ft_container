#include <iostream>
//#include "ft_containers.hpp"
#include <memory>
#include <vector>

using namespace std;
int main()
{
    //allocator<int> myAllocator;
    //ft::vector<int> ar(10); 
    std::vector<int> ar;

    ar.push_back(1);
    ar.push_back(-6);
    ar.push_back(8);
    ar.push_back(9);
    ar.push_back(4);

    std::vector <int>::iterator it = ar.begin();
    std::vector<int>::reverse_iterator rit = ar.rbegin();
    while (rit != ar.rend())
    {
        std::cout << *rit << std::endl;
        rit++;
    }
}