#include "Polygon.h"
#include <iostream>
#include <cmath>
#include <vector>

Polygon::Polygon() {}


Polygon::Polygon(const std::vector<Point>& points): points_(points){}


bool Polygon::get_vertex(int idx, Point& p) const{
    idx -= 1;
    if (0 <= idx && idx  < (int) points_.size()) {
        p = points_[idx];
        return true;
    }
    return false;
}


void Polygon::add_vertex(int idx, Point vertex){
    points_.insert(points_.begin() + idx - 1, vertex);
}


double Polygon::perimeter() const {
    double per = 0;
    for (int k = 0; k < (int) points_.size() ; k++) {
        Point p0 = points_[k];
        Point p1 = points_[k == ((int) points_.size() - 1)? 0:k+1];
        per += std::sqrt(std::pow(p0.get_x() - p1.get_x(), 2) + std::pow(p0.get_y() - p1.get_y(), 2));
    }
    return per;
}


void Polygon::show() const{
    std::cout << '{';
    for (Point point: points_) {
        point.show();
    } 
    std::cout << '}';
}