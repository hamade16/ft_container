#include <iostream>
#include "vector.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <vector>

using namespace std;
int main()
{
  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  //myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  // ft::vector<int> first;
  // ft::vector<int> second;
  // std::vector<int> third;


  // first.assign (7,100);
  // ft::vector<int>::iterator it;
  // it=first.begin()+1;
  // second.assign (it,first.end()-1);
  // int myints[] = {1776,7,4};
  // third.assign (myints,myints+3);

  // std::cout << "Size of first: " << int (first.size()) << '\n';
  // std::cout << "Size of second: " << int (second.size()) << '\n';
  // std::cout << "Size of third: " << int (third.size()) << '\n';
//   ft::vector<int> myvector (3,100);
//  // std::cout << myvector[0] << std::endl;
//   ft::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200);
//   myvector.insert (it,2,300);
//   // it = myvector.begin();
//   ft::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());
//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);
//   std::cout << "myvector contains:";
//    for (it=myvector.begin(); it<myvector.end(); it++)
//       std::cout << ' ' << *it;
//     std::cout << '\n';
    // std::vector<int> v(1, 15);
    // v.push_back(20);
    // v.push_back(25);
    // v.push_back(30);
    // std::reverse_iterator<std::vector<int>::iterator> it_rev;
    // it_rev = v.rend();
    // std::cout << it_rev[3] << std::endl;
    // EQUAL(((*my_rit == *(v.end() - 1)) && (&(*my_rit) == &(*(v.end() - 1)))) && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));

  //   ft::vector<int> myvector;
  // for (int i=0; i<10; i++) myvector.push_back(i);

  // ft::reverse_iterator<ft::vector<int>::iterator> from,until;

  // from = myvector.rbegin();
  // until = myvector.rend();


//   std::cout << "myvector has " << (until-from) << " elements.\n";

  return 0;
    //std::vector<int>::iterator iii;
    //ft::vector<int> vect(1, 11);
    //vect.push_back(44);
    //vect.push_back(55);
    //vect.push_back(66);
    //ft::vector<int>::iterator it = 1 + vect.begin();
    //ft::vector<int>::iterator it_end = vect.end();

   // it = 1 + it;
    //it += 1;
    //it_end -= 1;
   // std::cout << it_end - it << std::endl;
    //for (; it != it_end; it_end--)
    //{
    //    std::cout << *it_end << std::endl;
    //}
    //vect.push_back(70);
//     std::vector<int> myvector;

//     std::vector<int>::iterator it = myvector.begin();


//     myvector.push_back(78);
//     myvector.push_back(16);
    
//     // now front equals 78, and back 16
    
//     myvector.front() -= myvector.back();
    
//     std::cout << "myvector.front() is now " << myvector.front() << '\n';
//     return 0;
//     //allocator<int> myAllocator;
//     //ft::vector<int> ar(10); 
//     /*ft::vector<int> ar(5, 2);
//     ft::vector<int> av(3, 3);
//     ar.pop_back();
//     ar.push_back(5);
//     ar.clear();
//     ar.push_back(200);
//     ar.push_back(100);
//     ar.swap(av);
//     for(int i = 0; i < ar.size(); i++)
//         std::cout << ar.at(i) << std::endl;
    
    
//     std::cout << "======" << std::endl;*/

//      /*for(int i = 0; i < av.size(); i++)
//         std::cout << av[i] << std::endl;*/
//    // system("leaks a.out");


//     //ar.push_back(1);
//     //ar.push_back(-6);
//     //ar.push_back(8);
//     //ar.push_back(9);
//     //ar.push_back(4);

//     //std::vector <int>::iterator it = ar.begin();
//     //std::vector<int>::reverse_iterator rit = ar.rbegin();
//     //while (rit != ar.rend())
//     //{
//     //    std::cout << *rit << std::endl;
//     //    rit++;
//     //}

    // class iter 
    // {
    //     public:
    //         int *p;

    //         iter(int *adress)
    //         {
    //             p = adress;
    //         }
    // };

    /*int *arr = new int(10);
    for (int i = 0; i < 10; i++)
        arr[i] = i * 20;

    int *it1(arr + 3);
    
    int *it = arr + 0;
    int *it_end = arr + 10;
    
    for (; it != it_end; it++)
    {
        std::cout << *it << std::endl;
    }*/




        
    // std::vector<int> v(10, 13);
    // std::vector<int>::iterator it = v.begin(); 
    // std::vector<int>::iterator ii_end = v.end(); 
    
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << v[i] << std::endl;
    // }
    
    
    // for (; it != ii_end; it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    
}