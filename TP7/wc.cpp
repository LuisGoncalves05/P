#include <fstream>
#include <iostream>
#include <sstream>
#include "wc.h"

using namespace std;

wcresult wc(const string& filename);

int main() {
    { wcresult r = wc("p2_test1.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //1 0 1
    { wcresult r = wc("p2_test2.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //6 13 92
    { wcresult r = wc("p2_test3.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //1 9 44
    { wcresult r = wc("p2_test4.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //4 9 51
    { wcresult r = wc("p2_test5.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    //39 188 1051
    return 0;
}


wcresult wc(const string& filename) {
    ifstream file (filename);
    string line;
    string word;
    wcresult stats = {0, 0, 0};
    while (getline(file, line)) {
        stats.bytes += line.size() + 1;
        istringstream l(line);
        while (l >> word) {
            stats.words++;
        }
        stats.lines++;
    }
    return stats;
}