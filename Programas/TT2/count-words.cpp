#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

int count(const string& fname, const string& word) {
    string line, fword;
    string nword = word;
    for_each(nword.begin(), nword.end(), [](char& c) {c = tolower(c);});
    int acc = 0;
    ifstream file(fname);
    while (file >> line) {
        istringstream ssline(line);
        while (ssline >> fword) {
            for_each(fword.begin(), fword.end(), [](char& c) {c = tolower(c);});
            if (fword == nword) acc++;
        }
    }
    return acc;
}

int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
    //4
    cout << count("p1_test_a.txt", "0") << '\n';
    //1
    cout << count("p1_test_a.txt", "code") << '\n';
    //0
    cout << count("p1_test_b.txt", "Collider") << '\n';
    //6
    cout << count("p1_test_b.txt", "you") << '\n';
    //21
    return 0;
}