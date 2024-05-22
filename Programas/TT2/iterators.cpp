#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end) {
    ostringstream oss;
    oss << "[";
    while (start != end) {
        oss << ' ' << *start;
        start++;
    }
    oss << " ]";
    return oss.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b) {
    int acc = 0;
    while (start != end) {
        if (*start == a) {
            *start = b;
            acc++;
        }
        start++;
    }
    return acc;
}
