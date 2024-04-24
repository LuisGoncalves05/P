#include "fraction.h"
#include <iostream>

fraction sum(const fraction fa[], int n);
int gcd(int a, int b);


int main()
{
    { const int n = 1;
      const fraction fa[n] { {1, 2} };
      cout << sum(fa, n) << '\n'; }
    //1/2
    { const int n = 2;
      const fraction fa[n] { {1, 2}, {-1, 3} };
      cout << sum(fa, n) << '\n'; }
    //1/6
    { const int n = 3;
      const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
      cout << sum(fa, n) << '\n'; }
    //-7/12
    { const int n = 4;
      const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
      cout << sum(fa, n) << '\n'; }
    //0
    { const int n = 5;
      const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
      cout << sum(fa, n) << '\n'; }
    //-13/60
    { const int n = 6;
      const fraction fa[n] { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
      cout << sum(fa, n) << '\n'; }
    //2
    return 0;
}

fraction sum(const fraction fa[], int n)
{
    fraction res = {0, 1};
    for (int i = 0; i < n; i++)
    {
        fraction f = fa[i];
        int m1 = f.den;
        int m2 = res.den;
        f.den *= m2;
        f.num *= m2;
        res.den *= m1; 
        res.num *= m1;
        res.num += f.num; 
        int div = gcd(res.num, res.den);
        res.den /= div;
        res.num /= div;
    }
    if (res.den < 0)
    {
        res.num *= -1;
        res.den *= -1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}