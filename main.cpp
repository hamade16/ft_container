#include <iostream>
#include <vector>
#include <memory>

using namespace std;
int main()
{
    allocator<int> myAllocator;
    int *p = myAllocator.allocate(10);

    int i= 0;
    while (i < 10)
    {
        myAllocator.construct(i+p, 0);
        cout << p[i] << endl;
        i++;
    }
    system("leaks a.out");
}