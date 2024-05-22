#include "Date.h"
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool operator< (Date a, Date b) {
    return a.getYear() != b.getYear() ? a.getYear() < b.getYear() : a.getMonth() != b.getMonth() ? a.getMonth() < b.getMonth() : a.getDay() < b.getDay();
}

ostream& operator<< (ostream& os, Date d) {
    return os << setfill('0') << setw(4) << d.getYear() << '/' << setw(2) << d.getMonth() << '/' << setw(2) << d.getDay();
}