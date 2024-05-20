#include <string>
#include <vector>
#include <sstream>
#include "print_string.h"
using namespace std;

void split(const string &s, vector<string> &v) {
    stringstream ss(s);
    string k;
    while (ss >> k) {
        v.push_back(k);
    }
}