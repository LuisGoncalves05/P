#include <vector>
#include <iostream>

using namespace std;


void show_vector(const vector<vector<int>>& v) {
    cout << "{";
    for (const auto& line : v) {
        cout << "{ ";
        for (const auto& elem: line) {
            cout << elem << ' ';
        }
        cout << "}";
        }
    cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n);

int main() {
    { vector<vector<int>> v = { {1,2,3}, {4,5,6}, {7,8,9} };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl; }
    //true{{ 5 6 6 }{ 8 9 9 }{ 8 9 9 }}
    { vector<vector<int>> v =
    { { 8,5,4,2,1 },
        { 1,2,4,5,9 },
        { 3,6,3,7,3 },
        { 5,7,8,1,4 },
        { 9,1,2,6,5 } };
        bool b = max_filter(v, 3);
        cout << boolalpha << b;
    show_vector(v); cout << endl; }
    //true{{ 8 8 5 9 9 }{ 8 8 7 9 9 }{ 7 8 8 9 9 }{ 9 9 8 8 7 }{ 9 9 8 8 6 }}
    { vector<vector<int>> v = { { 8,5,4,2,1 }, { 9,1,2,6,5 } };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl; }
    //false{{ 8 5 4 2 1 }{ 9 1 2 6 5 }}
    { vector<vector<int>> v =
        { { -8,-5,4,2,1,-1,7 },
        { -1,-2,4,5,9,0,4 },
        { -3,6,-3,-7,3,-10,-7 },
        { 5,7,8,1,4,-2,-31 },
        { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl; }
    //true{{ -1 4 5 9 9 9 7 }{ 6 6 6 9 9 9 7 }{ 7 8 8 9 9 9 4 }{ 7 8 8 8 6 5 -2 }{ 7 8 8 8 6 5 -2 }}
    { vector<vector<int>> v =
        { { -8,-5,4,2,1,-1,7 },
        { -1,-2,4,5,9,0,4 },
        { -3,6,-3,-7,3,-10,-7 },
        { 5,7,8,1,4,-2,-31 },
        { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 5); cout << boolalpha << b;
    show_vector(v); cout << endl; }
    //true {{ 6 6 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 8 8 8 6 5 }}
    return 0;
}

bool max_filter(vector<vector<int>> &v, int n) {
    if (n % 2 == 1 && n <= (int) v.size() && n <= (int) v[0].size()) {
        vector<vector<int>> arr ((int)v.size(), vector<int>(v[0].size()));
        for (int i = 0; i < (int) v.size(); i++) {
            for (int j = 0; j < (int) v[0].size(); j++) {
                int max = v[i][j];
                for (int l = -n/2; l <= n/2; l++) {
                    for (int c = -n / 2; c <= n / 2; c++) {
                        int new_i = i + l;
                        int new_j = j + c;
                        if (new_i >= 0 && new_i < (int) v.size() &&
                            new_j >= 0 && new_j < (int) v[0].size()) {
                            if (v[new_i][new_j] > max) {
                                max = v[new_i][new_j];
                            }
                        }
                    }
                arr[i][j] = max;
                }
            }
        }
        for (int i = 0; i < (int) v.size(); i++) {
            for (int j = 0; j < (int)v[0].size(); j++) {
                v[i][j] = arr[i][j];
            }
        }
        return true;
    } else {
        return false;
    }
}