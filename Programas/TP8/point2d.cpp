#include <iostream>
#include "Point2d.h"
#include <cmath>


void Point2d::translate(const Point2d& t) {
    x += t.x;
    y += t.y;
}

double Point2d::distance_to(const Point2d& b) const{
    return sqrt(pow(x-b.x,2) + pow(y-b.y,2));
}