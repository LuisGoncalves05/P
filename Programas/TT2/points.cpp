#include "Point.h"
#include <iostream>

using namespace std;

Point operator*(int x, const Point& p) {
    return {p.get_x() * x, p.get_y() * x};
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.get_x() << ',' << p.get_y() << ')';
}

Point::Point(): Point(0, 0) {}

Point::Point(int x, int y): x_(x), y_(y) {}

Point::Point(const Point& p): x_(p.get_x()), y_(p.get_y()) {}

int Point::get_x() const {return x_;}

int Point::get_y() const {return y_;}

Point& Point::operator=(const Point& p){
    x_ = p.get_x();
    y_ = p.get_y();
    return *this;
}

Point Point::operator+(const Point& p) const{
    return {get_x() + p.get_x(), get_y() + p.get_y()};
}

Point& Point::operator+=(const Point& p){
    x_ += p.get_x();
    y_ += p.get_y();
    return *this;
}

Point Point::operator*(int v) const {
    return {v * get_x(), v * get_y()};
}
