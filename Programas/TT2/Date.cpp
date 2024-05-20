#include "Date.h"

using namespace std;

Date::Date(): Date(1, 1, 1) {}

Date::Date(int year, int month, int day): year_(year), month_(month), day_(day) {}

bool Date::is_before(const Date& date) const {
    int y = date.year_ ;
    int m = date.month_;
    int d = date.day_;
    if (year_ != y) return year_ < y;
    if (month_ != m) return month_ < m;
    return day_ < d;
}
