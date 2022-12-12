#include "map.hpp"


int main()
{
  
  ft::map<int, char> my_m;
  ft::map<int, char>::const_iterator my_it;
  ft::map<int, char>::iterator my_it1;
  my_it = my_m.begin();
   //ft::map<char,std::string> mymap;

  // mymap['a']="an element";
  // mymap['b']="another element";
  // mymap['c']=mymap['b'];

  // std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  // std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  // std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  // std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  // std::cout << "mymap now contains " << mymap.size() << " elements.\n";


  return 0;
}