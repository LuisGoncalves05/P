#include "wc.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

wcresult wc(const string& filename) {
    ifstream ifs(filename);
    string line;
    size_t lines = 0;
    size_t words = 0;
    size_t bytes = 0;
    while (getline(ifs, line)) {
        bytes += line.size() * sizeof(char) + 1;
        lines ++;
        istringstream sline(line);
        string word;
        while (sline >> word) {
            words++;
        }
    }
    return {lines, words, bytes};
}