#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    char c;
    int chars = 0;
    int nums = 0;
    int other = 0;
    for (int i = 0; i < n; i++){
        cin >> c;
        if (c >= '0' && c <= '9'){
            nums++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            chars ++;
        } else { 
            other++;
        }
    }
    cout << chars << ' ' << nums << ' ' << other;
    return 0;
}