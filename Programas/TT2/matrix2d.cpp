#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int transform(int i, int j, int n, vector<vector<int>> &v);

void show_vector(const vector<vector<int>>& v) {
    cout << "{";
    for (const auto& line : v) {
        cout << "{ ";
        for (const auto& elem : line)
            cout << elem << ' ';
        cout << "}";
    }
    cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n) {
    vector<vector<int>> vc(v.size(), vector<int>(v[0].size()));
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[0].size(); j++) {
            vc[i][j] = v[i][j];
        }
    }
    if (n % 2 == 0 || (int) v.size() < n || (int) v[0].size() < n) {
        return 0;
    } else {
        for (int i = 0; i < (int) v.size(); i++) {
            for (int j = 0; j < (int) v[0].size(); j++) {
                v[i][j] = transform(i, j, n, vc);
            }
        }
        return 1;
    }
}

int transform(int i, int j, int n, vector<vector<int>> &v) {
    vector<int> acc;
    for (int i_inner = i - n/2; i_inner <= i + n/2; i_inner++) {
        for (int j_inner = j - n/2; j_inner <= j + n/2; j_inner++) {
            if (i_inner >= 0 && i_inner < (int) v.size() &&
                j_inner >= 0 && j_inner < (int) v[0].size()) {
                acc.push_back(v[i_inner][j_inner]);
            }
        }
    }
    return *max_element(acc.begin(), acc.end());
}