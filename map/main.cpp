#include "map.hpp"


int main()
{
  ft::map<int, std::string> ft_m3;
  for (size_t i = 0; i < 1e6; i++)
  {
      ft_m3.insert(ft::make_pair(i, "string1"));
  }

//  for (size_t i = 0; i < 1e6; ++i)
//         {
//             int n = distr(generator);
//             int ret1 = m3.erase(n);
//             int ret2 = ft_m3.erase(n);

//             if (ret1 != ret2)
//             {
//                 cond = false;
//                 break;
//             }
//         }

 if (!ft_m3.empty())
  {
      ft_m3.erase(ft_m3.begin(), ft_m3.end());
      ft_m3.erase(ft_m3.begin(), ft_m3.end());
  }

  return 0;
}