#include <iostream>
#include <vector>
#include <sstream>
#include "Point.h"


using namespace std;

int main() {
    { Point a, b(1,2), c(b), d(3,4); 
    b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    //(0,0) (0,0) (1,2) (3,4)
    { Point a, b(1,2), c(b), d(3,4); 
    c = b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    //(0,0) (0,0) (0,0) (3,4)
    { Point a(1,2), b(3,4), c = a + b, d(5,6);
    b += d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    //(1,2) (8,10) (4,6) (5,6)
    { Point a(1,2), b(3,4), c = a * 2, d(5,6);
    b = 2 * d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    //(1,2) (10,12) (2,4) (5,6)
    { Point a(1,1), b(0,1), c(1,0), d(1,1);
    d += c += b += a += {1,2};
    d = 2 * d * 2;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    //(2,3) (2,4) (3,4) (16,20)
    return 0;
}

Point::Point(int x, int y) : x_(x), y_(y) {}

Point::Point() : Point(0, 0) {}

Point::Point(const Point &p) : x_(p.get_x()), y_(p.get_y()){}

int Point::get_x() const { return x_; }

int Point::get_y() const { return y_; }

Point& Point::operator=(const Point& p){
    this->x_ = p.get_x();
    this->y_ = p.get_y();
    return *this;
}

Point Point::operator+(const Point& p) const{
    return {get_x() + p.get_x(), get_y() + p.get_y()};
}

Point& Point::operator+=(const Point& p){
    *this = {get_x() + p.get_x(), get_y() + p.get_y()};
    return *this;
}

Point Point::operator*(int v) const{
    return {get_x() * v, get_y() * v};
}

Point operator*(int x, const Point& p){
    return {p.get_x() * x, p.get_y() * x};
}

ostream& operator<<(ostream& os, const Point& p){
    return os << "(" << p.get_x() << "," << p.get_y() << ")";
}