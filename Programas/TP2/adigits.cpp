#include <iostream>
using namespace std;

int adigits(int a, int b, int c);

int main(){
    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';
    return 0;
}


int adigits(int a, int b, int c) {
    if (a >= b && b >= c) {
        return a*100 + b*10 + c;
    } else if (a >= c && c >= b){
        return a*100 + c*10 + b;
    } else if (b >= a && a >= c){
        return b*100 + a*10 + c;
    } else if (b >= c && c >= a){
        return b*100 + c*10 + a;
    } else if (c >= a && a >= b){
        return c*100 + a*10 + b;
    } else {
        return c*100 + b*10 + a;
    }
}