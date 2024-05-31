#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <utility>

using namespace std;

string cat_keys(list<map<string, unsigned>> lst) {
    unsigned min = UINT_MAX;
    string s;
    for (auto m: lst) {
        unsigned minim = (*min_element(m.begin(), m.end(),
        [] (pair<string, unsigned> a, pair<string, unsigned> b) {return a.second < b.second;}))
        .second;
        if (minim < min) {
            min = minim;
            s = "";
            for (auto p: m) {
                s += p.first;
            }
        }
    }
    return s;
}



