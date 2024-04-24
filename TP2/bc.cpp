#include <iostream>
using namespace std;

unsigned long bc(unsigned long n, unsigned long k);


int main(){
    cout << bc(5, 0) << '\n';
    //1
    cout << bc(5, 1) << '\n';
    //5
    cout << bc(5, 5) << '\n'; 
    //1
    cout << bc(5, 2) << '\n';
    //10
    cout << bc(12, 7) << '\n'; 
    //792
    cout << bc(20, 10) << '\n'; 
    //184756
    return 0;
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