#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "show_file.h"

using namespace std;

void calc_medians(const string& input_fname, const string& output_fname);


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
	//*u4 -0.5
	{ calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
	show_file("p5_test4_out.txt"); }
	//==> p5_test4_out.txt <==
	//___a 1.0
	//___b 1.0
	//___c 0.5
	//___d 1.0
	{ calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
	show_file("p5_test5_out.txt"); }
	//==> p5_test5_out.txt <==
	//___a 1.0
	//___b 1.0
	//___c 0.5
	//___d 1.0
	return 0;
}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream fileinp (input_fname);
    ofstream fileout (output_fname);
    string l;
    while (getline(fileinp, l)) {
        if (l[0] != '#') {
            stringstream ss (l);
            string letter;
            ss >> letter;
            double x;
            double median = 0;
            int i = 0;
            
            vector<double> vec;
            while (ss >> x) {
                vec.push_back(x);
                i++;
            }

            sort(vec.begin(), vec.end());
            if (i % 2 == 0) {
                median = 0.5*(vec[i/2-1] + vec[i/2]);
            } else {
                median = vec[i/2];
            }
            fileout << letter  << ' ' << fixed << setprecision(1) << median << endl;
        }
    }
}