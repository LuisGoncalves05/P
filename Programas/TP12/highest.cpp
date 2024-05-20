#include <map>
#include <vector>
#include <utility>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    vector<pair<string, float>> v;
    for(pair<string, list<int>> kv: m) {
        list<int> l = kv.second;
        float acc = 0;
        for (int i: l) {
            acc += i;
        }
        v.push_back({kv.first, acc / l.size()});
    }
    return max_element(v.begin(), v.end(), [](pair<string, float> a, pair<string, float> b)
    {return a.second < b.second;})->first;
}
