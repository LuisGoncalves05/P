#include <iostream>
using namespace std;


unsigned long bell(unsigned long n);
unsigned long bc(unsigned long n, unsigned long k);


int main()
{
    cout << bell(0) << '\n';
    //1
    cout << bell(1) << '\n';
    //1
    cout << bell(2) << '\n';
    //2
    cout << bell(3) << '\n';
    //5
    cout << bell(4) << '\n';
    //15
    cout << bell(6) << '\n';
    //203
    return 0;
}


unsigned long bell(unsigned long n)
{
    if (n <= 1)
    {
        return 1;
    }
    unsigned long res = 0;
    for (unsigned long k = 0; k <= n-1; k++)
    {
        res += bc(n-1, k) * bell(k);
    }
    return res;
}


unsigned long bc(unsigned long n, unsigned long k){
    unsigned long lower = 1;
    for (unsigned long i = k; i >= 1; i--) {
        lower *= i;
    }
    unsigned long upper = 1;
    for (unsigned long i = n; i >= n-k+1; i--) {
        upper *= i;
    }
    return upper/lower;
}