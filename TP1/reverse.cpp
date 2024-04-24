#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a;
    while (a) {
        b = a % 10;
        a = a/10;
        cout << b;
    }
    return 0;
}