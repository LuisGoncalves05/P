#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle: public Shape
{
    public:
        Circle(const point& center, double radius)
        : Shape(center), radius_(radius)
        {}

        double area() const {
            return M_PI * radius_ * radius_;
        }

        double perimeter() const {
            return M_PI * radius_ * 2;
        }

        bool contains(const point& p) const {
            return sqrt(pow(get_center().x - p.x, 2) + pow(get_center().y - p.y, 2)) <= radius_;
        }

    private:
        double radius_;
};

#endif