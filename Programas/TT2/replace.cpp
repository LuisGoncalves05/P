#include <string>
#include <map>
#include <algorithm>

using namespace std;

void replace(const map<char, char>& r, string& s) {
    for_each(s.begin(), s.end(), [r](char& c) {c = r.find(c) != r.end() ? r.at(c): c;} );
}