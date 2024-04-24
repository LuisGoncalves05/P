#include <iostream>
#include <cmath>
#include <iomanip>


int main(){
    int k, d;
    std::cin >> k >> d;
    double approx = 0;
    for (int i = 0; i <= k; i++){
        approx += 4*pow(-1, i)/(2*i+1);
    }
    std::cout << std::fixed << std::setprecision(d) << approx;
    return 0;
}