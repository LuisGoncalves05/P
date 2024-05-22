#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <map>
#include <iostream>


using namespace std;

void count_words(const string& str, vector<pair<string, size_t>>& count) {
    istringstream iss(str);
    string w;
    map<string, size_t> m;
    while (iss >> w) {
        for (char& c: w) {
            c = tolower(c); 
        }
        m[w]++;
    }
    for (auto i: m) {
        count.push_back(i);
    }
}

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}