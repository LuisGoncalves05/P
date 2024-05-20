#include "Date2.h"
#include <string>
#include <sstream>
#include <map>

using namespace std;

bool check_date(int y, int m, int d);

Date::Date(int year, int month, int day): year(year), month(month), day(day) {
    if (!check_date(year, month, day)) {
        this->year = this->month = this->day = 0; 
    }
}

Date::Date(): Date(1, 1, 1) {}

Date::Date(const std::string& year_month_day) {
    istringstream iss(year_month_day);
    int year, month, day;
    char bs1, bs2;
    iss >> year >> bs1 >> month >> bs2 >> day;
    if (bs1 == '/' && bs2 == '/' && check_date(year, month, day)) {
        *this = Date(year, month, day);
    } else {
        this->year = this->month = this->day = 0; 
    }
}

bool Date::is_valid() const {
    return year && month && day;
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