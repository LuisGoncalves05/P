#include "Date3.h"
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <iomanip>


using namespace std;

bool check_date(int y, int m, int d);

Date::Date(int year, int month, int day) {
    ostringstream oss;
    oss << setfill('0') << setw(4) << year << setw(2) << month << setw(2) << day;
    if (check_date(year, month, day)) {
        yyyymmdd = oss.str();
    } else {
        yyyymmdd = "00000000";
    }
}

Date::Date(): Date(1, 1, 1) {}

Date::Date(const std::string& year_month_day) {
    istringstream iss(year_month_day);
    int year, month, day;
    char bs1, bs2;
    iss >> year >> bs1 >> month >> bs2 >> day;
    if (!(bs1 == '/' && bs2 == '/')) {
        year = month = day = 0;
    }
    *this = Date(year, month, day);
}

bool Date::is_valid() const {
    return yyyymmdd != "00000000";
}

bool check_date(int y, int m, int d) {
    map<int, int> mdays =  {{1, 31},
                            {2, 28},
                            {3, 31},
                            {4, 30},
                            {5, 31},
                            {6, 30},
                            {7, 31},
                            {8, 31},
                            {9, 30},
                            {10, 31},
                            {11, 30},
                            {12, 31}
                           };
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        mdays[2] = 29;
    }
    return y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= mdays[m];
}