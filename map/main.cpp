#include "map.hpp"
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>


int main()
{
     ft::map<std::string, std::string, std::greater<std::string> > ft_m1;
     ft_m1["a"] ="gamma";
     ft_m1["b"] ="camma";
    return 0;
}