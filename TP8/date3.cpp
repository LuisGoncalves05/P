#include "Date3.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;


Date::Date(): Date(1, 1, 1) {}


Date::Date(int year, int month, int day): yyyymmdd("00000000"){
    if (!(day > Date::num_days(year, month) || day < 1 || month > 12 ||month < 1 || year > 9999 || year < 1)) {
        stringstream ss;
        ss << setw(4) << setfill('0') << year;
        ss << setw(2) << setfill('0') << month;
        ss << setw(2) << setfill('0') << day;
        ss.str();
        yyyymmdd = ss.str();
    }
}


Date::Date(const std::string& year_month_day): yyyymmdd("00000000") {
    istringstream iss (year_month_day);
    int y, m, d;
    char sep1, sep2;
    if ((iss >> y >> sep1 >> m >> sep2 >> d) && (sep1 == '/') && (sep2 == '/')) {
        if (!(d > Date::num_days(y, m) || d < 1 || m > 12 || m < 1 || y > 9999 || y < 1)) {
            stringstream ss;
            ss << setw(4) << setfill('0') << y;
            ss << setw(2) << setfill('0') << m;
            ss << setw(2) << setfill('0') << d;
            yyyymmdd = ss.str();
        }
    }
}


int Date::num_days(int y, int m) {
    vector<int> months = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    months[2] = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)? 29 : 28;
    return months[m];
}



bool Date::is_valid() const{
    return (yyyymmdd.substr(0, 4) != "0000" && yyyymmdd.substr(4, 2) != "00" && yyyymmdd.substr(6, 2) != "00");
}