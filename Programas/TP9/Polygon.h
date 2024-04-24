#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>

class Polygon {
    public:
        Polygon();
        Polygon(const std::vector<Point>& points);
        bool get_vertex(int idx, Point& p) const;
        void add_vertex(int idx, const Point vertex);
        double perimeter() const;
        void show() const;
    private:
        std::vector<Point> points_ = {};
};

#endif