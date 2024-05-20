#include <fstream>
#include <string>

using namespace std;

double average(const string fname) {
    ifstream ifs(fname);
    double avg = 0;
    int n = 0;
    while (true) {
        double num;
        if (ifs >> num) {
            n++;
            avg += num;
        } else {
            if (ifs.eof()) break;
            ifs.clear();
            ifs.ignore();
        }
    }
    return avg / n;
}
