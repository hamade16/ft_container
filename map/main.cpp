#include "avl.hpp"
#include <map>


int main()
{
    // Node<int÷÷> node(10);
    std::map<int, char> map;

    std::pair<int, char> val(1337, 'H');
    
    map.insert(val);
    
    std::cout << map.at(1337);


    return 0;
}