#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2);


int main() {
    {   double x1, x2; 
        int r = solve_eq(1, 1, 0, x1, x2); 
        cout << fixed << setprecision(7) 
        << r << ' ' << x1 << ' ' << x2 << '\n'; }
    //2 -1.0000000 0.0000000
    {   double x1, x2; 
        int r = solve_eq(1, -2, 1, x1, x2); 
        cout << fixed << setprecision(7) 
        << r << ' ' << x1 << ' ' << x2 << '\n'; }
    //1 1.0000000 nan
    {   double x1, x2; 
        int r = solve_eq(1, 1, 1, x1, x2); 
        cout << fixed << setprecision(7) 
        << r << ' ' << x1 << ' ' << x2 << '\n'; }
    //0 nan nan
    {   double x1, x2; 
        int r = solve_eq(1, -1, 0, x1, x2); 
        cout << fixed << setprecision(7) 
        << r << ' ' << x1 << ' ' << x2 << '\n'; }
    //2 0.0000000 1.0000000
    {   double x1, x2; 
        int r = solve_eq(3, 4, -2, x1, x2); 
        cout << fixed << setprecision(7) 
        << r << ' ' << x1 << ' ' << x2 << '\n'; }
    //2 -1.7207592 0.3874259
    return 0;
}

int solve_eq(int a, int b, int c, double& x1, double& x2) {
    int delta = b*b-4*a*c;
    if (delta < 0) {
        x1 = NAN;
        x2 = NAN;
        return 0;
    } else if (delta == 0) {
        x1 = -b/(2.0*a);
        x2 = NAN;
        return 1;
    } else {
        double sq =sqrt(delta);
        x1 = (-b-sq)/(2.0*a);
        x2 = (-b+sq)/(2.0*a);
        return 2;
    }
}