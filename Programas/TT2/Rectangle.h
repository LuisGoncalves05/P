#include "Shape.h"
#include <cmath>

using namespace std;

class Rectangle: public Shape {
    public:
        Rectangle(const point& center, double width, double height): Shape(center), width_(width), height_(height) {}

        double area() const {
            return width_ * height_;
        }

        double perimeter() const {
            return width_ * 2 + height_ * 2;
        }

        bool contains(const point& p) const {
            return  p.y <= get_center().y + height_ / 2 &&
                    p.y >= get_center().y - height_ / 2 &&
                    p.x <= get_center().x + width_ / 2 &&
                    p.x >= get_center().x - width_ / 2;
        }

    private:
        double width_, height_;
};