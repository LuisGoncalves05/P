#include "Date1.h"


Date::Date(): Date(1, 1, 1) {}


Date::Date(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}


int Date::get_day() const{
    return day;
}


int Date::get_month() const{
    return month;
}


int Date::get_year() const{
    return year;
}


bool is_before(const Date& date1, const Date& date2) {
    int d1 = date1.get_day();
    int m1 = date1.get_month();
    int y1 = date1.get_year();
    int d2 = date2.get_day();
    int m2 = date2.get_month();
    int y2 = date2.get_year();
    if (y1 < y2) {
        return true;
    }
    if (y1 == y2) {
        if (m1 < m2) return true;
        if ((m1 == m2) && (d1 < d2)) return true;
    }
    return false;
}