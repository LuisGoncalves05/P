#include <iostream>
using namespace std;


bool isprime(int n) {
    bool prime = true;
    if (n == 1) return false;
    for (int j = 2; j < n; j++) {
        if (n%j == 0){
            prime = false;
        }
    }
    return prime;
}


bool ispernicious(int n){
    int counter = 0;
    int lsb;
    while (n != 0){
        lsb = n & 1;
        counter += lsb;
        n = n >> 1;
    }
    return isprime(counter);
}


int main(){
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (isprime(i) && ispernicious(i)){
            cout << i << ' ';
        }
    }
    return 0;
}