#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "show_file.h"

using namespace std;

void average(const string& input_fname, const string& output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string line;
    int lines = 0;
    while (getline(ifs, line)) {
        double d;
        double avg = 0;
        int count = 0;
        istringstream iss(line);
        while (iss >> d) {
            count++;
            avg += d;
        }
        ofs << fixed << setprecision(3) << avg/count << endl;
        lines++;
    }
    ofs << "lines=" << lines;
}