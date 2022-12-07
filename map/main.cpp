#include "map.hpp"


int main()
{
    // std::map<char*, char*> p;
    // p.insert(std::make_pair("h", "hshhs"));
    // std::map<char*, char*>::iterator  it = p.begin();
    // std::cout << *it->first << std::endl;
   ft::map<char,std::string> mymap;

  mymap['a'];
  mymap['b']; 
  mymap['c']; 
// std::cout << mymap.size() << std::endl;

//   ft::map<char , std::string>::iterator it;
//   for (it = mymap.begin(); it != mymap.end(); it++)
//   {
//     std::cout << "key = " << it->first << " value = " << it->second << std::endl;
//   }
  // std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  // std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  // std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  // std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  // std::cout << "mymap now contains " << mymap.size() << " elements.\n";

    return 0;
}