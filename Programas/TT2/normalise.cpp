#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "print.h"

using namespace std;

void normalise(const string& input_fname, const string& output_fname) {
    bool first = true;
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string line;
    while (getline(ifs, line)) {
        int end = -2, start = (int) line.size() - 1;
        if ((int) line.size() > 0) {
            for (int i = 0; i < (int) line.size(); i++) {
                if (line[i] != ' ') {start = i; break;}
            }
            for (int i = 0; i < (int) line.size(); i++) {
                if (line[line.size() - 1 - i] != ' ') {end = line.size() - 1 - i; break;}
            }
        }
        if (start <= end && line[start]) {
            line = line.substr(start, end - start + 1);
            for_each(line.begin(), line.end(), [](char&c) {c = toupper(c);});
            if (!first) {
                ofs << endl;
            }
            ofs << line;
            first = false;
        }
    }
    ofs.close();
}