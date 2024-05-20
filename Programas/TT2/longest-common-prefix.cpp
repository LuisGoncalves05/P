#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longest_prefix(const vector<string> &v) {
    unsigned int min = -1;
    for (string s: v) {
        if (s.length() < min) min = s.length(); 
    }
    string verified = "";
    for (unsigned int i = 1; i <= min; i++) {
        string pref = v[0].substr(0, i);
        for (string s: v) {
            if (s.substr(0, i) != pref) return verified;
        }
        verified = pref;
    }
    return verified;
}