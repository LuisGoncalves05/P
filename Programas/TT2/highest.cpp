#include <map>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    vector<pair<string, double>> v;
    for (pair<string, list<int>> s: m) {
        double avg = accumulate(s.second.begin(), s.second.end(), 0.0) / s.second.size();
        v.push_back({s.first, avg});
    }
    sort(v.begin(), v.end(), [](pair<string, double> p, pair<string, double> q) {return p.second < q.second;});
    return v[v.size() - 1].first;
}