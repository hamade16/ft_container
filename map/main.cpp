#include "map.hpp"


int main()
{
  ft::map<char,int> mymap;

  //ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

ft::map<char, int>::reverse_iterator _it;
_it = mymap.rbegin();
//_it--;
std::cout << _it->first << std::endl;


  // std::cout << "mymap contains:\n";

  // char highest = mymap.rbegin()->first;     // key value of last element

  // std::map<char,int>::iterator it = mymap.begin();
  // do {
  //   std::cout << it->first << " => " << it->second << '\n';
  // } while ( mycomp((*it++).first, highest) );

  // std::cout << '\n';
  return 0;
}