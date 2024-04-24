#include <iostream>
using namespace std;


void advance(int delta, int& d, int& m, int& y);
bool is_leap(int year);
int days_in_month(int month, int year);

int main(){
    { int d = 1, m = 1, y = 2022; 
        advance(0, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 1, m = 10, y = 2022; 
        advance(10, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 2, m = 6, y = 2022; 
        advance(31, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 2, m = 7, y = 2022; 
        advance(31, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 25, m = 2, y = 2000; 
        advance(4, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 25, m = 2, y = 2001; 
        advance(4, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 2, m = 12, y = 1900; 
        advance(365 + 5, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    { int d = 31, m = 3, y = 1903; 
        advance(365 + 366 + 30 + 5, d, m, y); 
        cout << d << ' ' << m << ' ' << y << '\n'; }
    return 0;
}


void advance(int delta, int& d, int& m, int& y){
    for (int i = 0; i < delta; i++) {
        if (d != days_in_month(m, y)) {
            d++;
        } else if (m != 12){
            d = 1;
            m++;
        } else {
            d = 1;
            m = 1;
            y++;
        }
    }
}


bool is_leap(int year) {
    return year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);
}


int days_in_month(int month, int year) {
    int days;
    switch (month) {
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if (is_leap(year)) {
                days = 29;    
            } else {
                days = 28;
            }
            break;
        default:
            days = 31;
    }
    return days;
}