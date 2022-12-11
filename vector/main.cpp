#include <iostream>
#include "vector.hpp"
#include "random_access_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include <memory>
#include <vector>

using namespace std;
int main()
{
  ft::vector<int> v;
  v.assign (7,100);


  // show content:
  ft::vector<int>::reverse_iterator rit;
  rit = v.rend();
  rit--;
  std::cout << *rit << std::endl;
  // ft::vector<int> first;
  // ft::vector<int> second;
  // ft::vector<int> third;

  // first.assign (7,100);             // 7 ints with a value of 100

  // ft::vector<int>::iterator it;
  // it=first.begin()+1;

  // second.assign (it,first.end()-1); // the 5 central values of first

  // int myints[] = {1776,7,4};
  // third.assign (myints,myints+3);   // assigning from array.

  // std::cout << "Size of first: " << int (first.size()) << '\n';
  // std::cout << "Size of second: " << int (second.size()) << '\n';
  // std::cout << "Size of third: " << int (third.size()) << '\n';


  // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " assign(range) method "
  //             << "] --------------------]\t\t\033[0m";
    {
        /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(40, "less");
        // std::vector<std::string> v2;
        // std::vector<std::string> v3(10, "string2");
        /*------------------ std::vectors ---------------------*/
        // ft::vector<std::string> ft_v1(40, "less");
        // ft::vector<std::string> ft_v2;
        // ft::vector<std::string> ft_v3(10, "string2");
        /*
         * Strings to store the results
         */
        //std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        // size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        // size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        // v3.assign(v1.begin(), v1.end());
        // ft_v3.assign(v1.begin(), v1.end());

        // z1 = v3.size();
        // c1 = v3.capacity();
        // ft_z1 = ft_v3.size();
        // ft_c1 = ft_v3.capacity();

        // std::cout << "dyalna => "  << ft_c1 << " " << ft_z1 << "\n";
        // std::cout << "dyalhom => " << c1 << " " << z1 << "\n";
        // for (size_t i = 0; i < v3.size(); ++i)
        //     s1 += v3.at(i);

        // for (size_t i = 0; i < ft_v3.size(); ++i)
        //     ft_s1 += ft_v3.at(i);
        // // test for n lesser than the vector capactiy
        // v1.assign(v3.begin(), v3.end());
        // ft_v1.assign(ft_v3.begin(), ft_v3.end());

        // z2 = v1.size();
        // c2 = v1.capacity();
        // ft_z2 = ft_v1.size();
        // ft_c2 = ft_v1.capacity();
        // for (size_t i = 0; i < v1.size(); ++i)
        //     s3 += v1.at(i);

        // for (size_t i = 0; i < ft_v1.size(); ++i)
        //     ft_s3 += ft_v1.at(i);
        // // test for empty vectors
        // v2.assign(v1.begin(), v1.end());
        // ft_v2.assign(ft_v1.begin(), ft_v1.end());

        // z3 = v2.size();
        // c3 = v2.capacity();
        // ft_z3 = ft_v2.size();
        // ft_c3 = ft_v2.capacity();
        // for (size_t i = 0; i < v2.size(); ++i)
        //     s2 += v2.at(i);

        // for (size_t i = 0; i < ft_v2.size(); ++i)
        //     ft_s2 += ft_v2.at(i);

        //EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1) && (s2 == ft_s2 && z2 == ft_z2 && c2 == ft_c2) && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
    }

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