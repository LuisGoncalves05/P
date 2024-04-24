#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int count(const string& fname, const string& word);
string uppercase(const string &x);

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';
    //4
    cout << count("p1_test_a.txt", "0") << '\n';
    //1
    cout << count("p1_test_a.txt", "code") << '\n';
    //0
    cout << count("p1_test_b.txt", "Collider") << '\n';
    //6
    cout << count("p1_test_b.txt", "you") << '\n';
    //21
    return 0;
}

int count(const string& fname, const string& word){
    ifstream file (fname);
    int counter = 0;
    string str;
    string word_uc = uppercase(word);
    while (file >> str){
        if (uppercase(str) == word_uc) {
            counter++;
        }
    }
    return counter;
}

string uppercase(const string &x) {
    string x_uc = x;
    for (char &c: x_uc) {
        c = toupper(c);
    }
    return x_uc;
}