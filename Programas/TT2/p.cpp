#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v0 = {2, 3, 4, 5, 6, 7};
    cout << *find_if(v0.begin(), v0.end(), [](int x){return x > 5;}) << endl;

    vector<int> v1 = {2, 3, 4, 5, 6, 7};
    int n = 5;
    cout << *find_if(v1.begin(), v1.end(), [=](int x){return x > n;}) << endl;

    vector<int> v2 = {2, 3, 4, 5, 6, 7};
    int k = 5;
    cout << *find_if(v2.begin(), v2.end(), [k](int x){return x > k;}) << endl;
    return 0;
}