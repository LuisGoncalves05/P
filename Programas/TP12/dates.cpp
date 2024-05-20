#include "Date.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool operator<(Date a, Date b) {
    if (a.getYear() < b.getYear())
        return 1;
    if (a.getYear() > b.getYear())
        return 0;
    if (a.getMonth() < b.getMonth())
        return 1;
    if (a.getMonth() > b.getMonth())
        return 0;        
    if (a.getDay() < b.getDay())
        return 1;
    return 0;
}

bool operator>(Date a, Date b) { return b < a; }

bool operator==(Date a, Date b) {
    return !(a<b||b>a);
}

ostream &operator<<(ostream &os, Date date) {
    os << setfill('0') << setw(4) << date.getYear() << '/' << setw(2) << date.getMonth() << '/' << setw(2) << date.getDay();
    return os;
}