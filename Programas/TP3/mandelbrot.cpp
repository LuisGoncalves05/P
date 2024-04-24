#include "complex.h"

void mul(const complex& a, const complex& b, complex& r);
void mandelbrot(const complex& c, unsigned int n, complex& z_n);


int main()
{
    { complex z_n;
    mandelbrot({1.2, 3.4}, 0, z_n);
    cout << z_n << '\n'; }
    //0.000+0.000i
    { complex z_n;
    mandelbrot({1, 1}, 1, z_n);
    cout << z_n << '\n'; }
    //1.000+1.000i
    { complex z_n;
    mandelbrot({1, 1}, 2, z_n);
    cout << z_n << '\n'; }
    //1.000+3.000i
    { complex z_n;
    mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n'; }
    //-0.624-2.499i
    { complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n'; }
    //2174.128-13121.836i
    { complex z_n;
    mandelbrot({-1, 0}, 11, z_n);
    cout << z_n << '\n'; }
    //-1.000+0.000i
    return 0;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n)
{
    if (n == 0)
    {
        z_n.x = 0;
        z_n.y = 0;
    }
    else
    {   
        complex res1, res2;
        mandelbrot(c, n-1, res1);
        mul(res1, res1, res2);
        z_n.x = c.x + res2.x;
        z_n.y = c.y + res2.y;
    }    
}

void mul(const complex& a, const complex& b, complex& r)
{
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}