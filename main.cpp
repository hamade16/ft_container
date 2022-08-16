#include <iostream>
#include "ft_containers.hpp"
#include <memory>
#include <vector>

using namespace std;
int main()
{
    //allocator<int> myAllocator;
    //ft::vector<int> ar(10); 
    ft::vector<int> ar(5, 2);
    ft::vector<int> x(ar);
    ar.pop_back();
    //ar.push_back(5);
    for(int i = 0; i < ar.size(); i++)
        std::cout << ar[i] << std::endl;
   // system("leaks a.out");


    //ar.push_back(1);
    //ar.push_back(-6);
    //ar.push_back(8);
    //ar.push_back(9);
    //ar.push_back(4);

    //std::vector <int>::iterator it = ar.begin();
    //std::vector<int>::reverse_iterator rit = ar.rbegin();
    //while (rit != ar.rend())
    //{
    //    std::cout << *rit << std::endl;
    //    rit++;
    //}
}