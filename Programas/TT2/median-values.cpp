#include <string>
#include <sstream> 
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iostream>
#include "show_file.h"

using namespace std;

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream ifs(input_fname);
    ofstream ofs(output_fname);
    string line;
    while (getline(ifs, line) && line != "") {
        if (line[0] != '#') {
            istringstream liness(line);
            string letter;
            liness >> letter;
            vector<double> v = {};
            double d;
            while (liness >> d) {
                v.push_back(d);
            }
            sort(v.begin(), v.end());
            if (v.size() % 2) {
                d = v[v.size()/2];
            } else {
                d = 0.5*(v[v.size()/2 - 1] + v[v.size()/2]);
            }
            ofs << letter << ' ' << fixed << setprecision(1) << d << endl;
        }
    }
    ofs.close();
}

int main() {
    { calc_medians("p5_test1.txt", "p5_test1_out.txt"); 
    show_file("p5_test1_out.txt"); }
    //==> p5_test1_out.txt <==
    //a 3.0
    { calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
    show_file("p5_test2_out.txt"); }
    //==> p5_test2_out.txt <==
    //b 1.1
    //c 1.3
    //d 1.0
    { calc_medians("p5_test3.txt", "p5_test3_out.txt"); 
    show_file("p5_test3_out.txt"); }
    //==> p5_test3_out.txt <==
    //u1 1.5
    //u2 2.0
    //u3 2.0
    //u4 -0.5
    { calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
    show_file("p5_test4_out.txt"); }
    //==> p5_test4_out.txt <==
    //___a 1.0
    //___b 1.0
    //___c 0.5
    //___d 1.0
    { calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
    show_file("p5_test5_out.txt"); }
    return 0;
}