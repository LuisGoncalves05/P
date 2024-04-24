#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std; 

double average(const string fname);

int main() {
    { double m = average("p6_test1.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //2.50
    { double m = average("p6_test2.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //2.50
    { double m = average("p6_test3.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //0.75
    { double m = average("p6_test4.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //1.00
    { double m = average("p6_test5.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    //3.50
    return 0;
}

double average(const string fname) {
    ifstream inpfile (fname);
    double val;
    double add2me = 0;
    int count = 0;
    while (!inpfile.eof()) {
        if (inpfile >> val) {
            add2me += val;
            count++;
        } else {
            inpfile.clear();
            inpfile.ignore(1);
        }
    }
    return add2me/count;
}