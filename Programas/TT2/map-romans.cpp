#include <utility>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<char, unsigned> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

unsigned roman_to_arab(const string& roman) {
    int acc = 0;
    for (int i = 0; i < (int) roman.length() - 1; i++) {
        if (roman_to_int[roman[i+1]]  > roman_to_int[roman[i]]) {
            acc += -roman_to_int[roman[i]];
        } else {
            acc += roman_to_int[roman[i]];
        }
    }
    acc += roman_to_int[roman[roman.length() - 1]];
    return acc;
}