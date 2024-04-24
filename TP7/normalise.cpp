#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "print.h"

void normalise(const string& input_fname, const string& output_fname);
void upper(string &str);
bool cleanline(string &str);

using namespace std;

int main() {
    { normalise("p3_test1.txt", "p3_test1_out.txt"); 
    print("p3_test1_out.txt"); }
    //1|WORD ONE|
    //2|WORD TWO|
    //3|WORD THREE SPACES FOLLOW|
    //4|AND ONE FINAL EMPTY LINE|
    { normalise("p3_test2.txt", "p3_test2_out.txt"); 
    print("p3_test2_out.txt"); }
    //1|C++|
    //2|LEIC UP|
    //3|PYTHON 3|
    //4|PYTHON 2|
    { normalise("p3_test3.txt", "p3_test3_out.txt"); 
    print("p3_test3_out.txt"); }
    //1|THE QUICK BROWN FOX Jvoid upper(string &str) E R  T H E|
    //4|L A Z Y|
    //5|D|
    //6|O|
    //7|G|
    { normalise("p3_test5.txt", "p3_test5_out.txt"); 
    print("p3_test5_out.txt"); }
    //1|ABCDEFGHIIJKLMOPQRSTUVWXYZ|
    //2|0123456789 0123456789 0123456789|
    //3|ABCDEFGHIIJKLMOPQRSTUVWXYZ|
    //4|0123456789 0123456789 0123456789|
    return 0;
}


void normalise(const string& input_fname, const string& output_fname) {
    ifstream fileinp (input_fname);
    string line;
    ofstream fileout (output_fname);
    while (getline(fileinp, line)) {
        if (cleanline(line)) {
            upper(line);
            fileout << line << endl;
        }
    }
}


bool cleanline(string &str){
    int start = (int) str.size();
	int end = -1;

    for(size_t i = 0; i < str.size(); i++){
        if (str[i] != ' ') {
            start = (int) i;
            break;
        }
    }
    for(int i = (int) str.size() - 1; i >= 0; i--){
        if (str[i] != ' ') {
            end = i;
            break;
        }
    }
	if (start <= end) {
		str = str.substr(start, end - start + 1);
		return true;
	} else { return false; }
}


void upper(string &str) {
    for (char &c: str) {
        c = toupper(c);
    }
}
