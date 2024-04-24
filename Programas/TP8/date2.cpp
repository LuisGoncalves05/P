#include "Date2.h"
#include <vector>
#include <sstream>

using namespace std;


Date::Date(): Date(1, 1, 1) {}


Date::Date(int year, int month, int day): year(year), month(month), day(day) {
    vector<int> months = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    months[2] = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)? 28 : 29;
    int days_m = months[month];
    if (day > days_m || day < 1 || month > 12 ||month < 1 || year > 9999 || year < 1) {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
}


Date::Date(const std::string& year_month_day): year(0), month(0), day(0) {
    istringstream iss (year_month_day);
    int y, m, d;
    char sep1, sep2;
    if ((iss >> y >> sep1 >> m >> sep2 >> d) && (sep1 == '/') && (sep2 == '/')) {
        vector<int> months = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        months[2] = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)? 29 : 28;
        int days_m = months[m];
        if (!(d > days_m || d < 1 || m > 12 || m < 1 || y > 9999 || y < 1)) {
            this->day = d;
            this->month = m;
            this->year = y;
        }
    }
}


bool Date::is_valid() const{
    return (day && month && year);
}