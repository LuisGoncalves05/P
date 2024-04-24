#include <iostream>
using namespace std;


unsigned long pell(unsigned long n);

int main()
{
    cout << pell(0) << '\n';
    //0
    cout << pell(1) << '\n';
    //1
    cout << pell(2) << '\n';
    //2
    cout << pell(3) << '\n';
    //5
    cout << pell(5) << '\n';
    //29
    cout << pell(50) << '\n';
    //4866752642924153522
    return 0;
}


unsigned long pell(unsigned long n)
{
    if (n <= 2)
    {
        return n;
    } 
    unsigned long a = 1;
    unsigned long b = 2;
    unsigned long c, i;
    
    for (i = 3; i <= n; i++)
    {
        c = 2 * b + a;
        a = b;
        b = c;
    }
    return b;
}