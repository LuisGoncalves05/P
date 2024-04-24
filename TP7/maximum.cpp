#include <iostream>
#include "show_file.h"
#include <iomanip>

using namespace std;
void maximum(const string& input_fname, const string& output_fname);


int main() {
	{ maximum("p4_test1.txt", "p4_test1_out.txt");
	show_file("p4_test1_out.txt"); }
	//==> p4_test1_out.txt <==
	//-1.200
	//1.222
	//3.142
	//count=3/max=3.142
	{ maximum("p4_test2.txt", "p4_test2_out.txt");
	show_file("p4_test2_out.txt"); }
	//==> p4_test2_out.txt <==
	//-11.223
	//-65.240
	//-3.142
	//count=3/max=-3.142
	{ maximum("p4_test3.txt", "p4_test3_out.txt");
	show_file("p4_test3_out.txt"); }
	//==> p4_test3_out.txt <==
	//-11.000
	//0.000
	//12.452
	//123.457
	//count=4/max=123.457
	{ maximum("p4_test4.txt", "p4_test4_out.txt");
	show_file("p4_test4_out.txt"); }
	//==> p4_test4_out.txt <==
	//1.223
	//1.200
	//3.146
	//count=3/max=3.146
	return 0;
}

void maximum(const string& input_fname, const string& output_fname) {
	double x;
	ifstream inpfile (input_fname);
	ofstream outfile (output_fname);
	int i = 0;
	double max;
	while (inpfile >> x) {
		outfile << fixed << setprecision(3) << x << endl;
		if (i == 0) {
			max = x;
		} else if (max < x) {
			max = x;
		}
		i++;
	}
	outfile << fixed << setprecision(3) << "count=" << i << "/max=" << max << endl;
}