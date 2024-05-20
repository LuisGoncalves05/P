#include "show_file.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    double max = -1000;
    double d;
    int count = 0;
    while(ifs >> d) {
        ofs << fixed << setprecision(3) << d << endl;
        count ++;
        max = d > max? d: max;
    }
    ofs << "count=" << count << "/max=" << setprecision(3) << max;
    ofs.close();
}