#include "Polygon.h"
#include <iostream>
#include <cmath>

using namespace std;

Polygon::Polygon(): Polygon(vector<Point>()) {}

Polygon::Polygon(vector<Point> points): points(points) {}

bool Polygon::get_vertex(int i, Point& p) {
    if (i >= 1 && i <= (int) points.size()) {
        p = points[i-1];
        return true;
    } else {
        return false;
    }
}

bool Polygon::add_vertex(int pos, Point vertex) {
    if (pos >= 1 && pos <= (int) points.size() + 1) {
        points.insert(points.begin() + pos - 1, vertex);
        return true;
    } else {
        return false;
    }
}

void Polygon::show() {
    cout << '{';
    for (Point p: points) {
        p.show();
    }
    cout << '}';
}

double Polygon::perimeter() {
    double acc = 0;
    for (int i = 0; i < (int) points.size() - 1; i++) {
        acc += sqrt(pow(points[i].x - points[i+1].x, 2) + pow(points[i].y - points[i+1].y, 2));
    }
    acc += sqrt(pow(points[points.size() - 1].x - points[0].x, 2) + pow(points[points.size() - 1].y - points[0].y, 2));
    return acc;
}