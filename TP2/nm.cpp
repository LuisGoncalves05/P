#include <iostream>
using namespace std;

unsigned long next_mersenne(unsigned long n);

int main()
{
    cout << next_mersenne(0) << '\n';
    //0
    cout << next_mersenne(1) << '\n';
    //1
    cout << next_mersenne(2) << '\n';
    //3
    cout << next_mersenne(4) << '\n';
    //7
    cout << next_mersenne(128) << '\n';
    //255
    cout << next_mersenne(4294967296UL) << '\n';
    //8589934591
    return 0;
}


unsigned long next_mersenne(unsigned long n)
{
    unsigned long result = 0;
    int i = 0;
    while (result < n)
    {
        result = (result + 1)*2 - 1; 
        ++i;
    }
    return result;
}