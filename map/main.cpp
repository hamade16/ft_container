#include "map.hpp"


int main()
{
    // std::map<char*, char*> p;
    // p.insert(std::make_pair("h", "hshhs"));
    // std::map<char*, char*>::iterator  it = p.begin();
    // std::cout << *it->first << std::endl;
   ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    return 0;
}