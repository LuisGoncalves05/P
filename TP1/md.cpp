#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int k, l, sum;
    sum = 0;
    cin >> k >> l;
    for (int i = 0; i < number; i++){
        int m, n, p1, p2;
        cin >> m >> n;
        p1 = k-m;
        if (p1 < 0) p1 = -p1;
        p2 = l-n;
        if (p2 < 0) p2 = -p2;
        sum += p1 + p2;
        k = m;
        l = n;
    }
    cout << sum << endl;
    return 0;
}