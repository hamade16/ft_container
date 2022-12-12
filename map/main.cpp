#include "map.hpp"


int main()
{
  
  std::map<char, int> first;
  //ft::map<char,int> m_first;
 ft::map<char, int> m_first;

    for (size_t i = 97; i < 110; i++)
    {
        first[i - 97] = i;
        m_first[i - 97] = i;
    }
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