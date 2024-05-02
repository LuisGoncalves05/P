#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end){
    string res = "[ ";
    while (start != end) {
        stringstream ss;
        ss << *start;
        res += ss.str();
        res += " ";
        start++;
    }
    res += "]";
    return res;
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int counter = 0;
    while (start != end)
    {
        if (*start == a) {
            *start = b;
            counter++;
        }
        start++;
    }
    return counter;
}
