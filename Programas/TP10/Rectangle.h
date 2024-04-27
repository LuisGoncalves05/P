#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape
{
    public:
        Rectangle(const point& center, double width, double height)
        : Shape(center), width_(width), height_(height)
        {}

        double area() const {
            return width_ * height_;
        }

        double perimeter() const {
            return 2 * (width_ + height_);
        }

        bool contains(const point& p) const {
            double lx = get_center().x - width_ / 2,
                   rx = get_center().x + width_ / 2,
                   ly = get_center().y - height_ / 2,
                   uy = get_center().y + height_ / 2;
            return p.x >= lx &&
                   p.x <= rx &&
                   p.y >= ly &&
                   p.y <= uy;
        }

    private:
        double width_;
        double height_;
};

#endif