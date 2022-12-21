#include <iostream>       // std::cout
#include <stack>  
#include "stack.hpp"        // std::stack

int main ()
{
  ft::stack<int> mystack;
  ft::stack<int> mystack2;
  mystack2.push(5);

  mystack.push(10);
  mystack.push(20);
   if (mystack2 != mystack)
     std::cout << "hdhdhd\n";

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}