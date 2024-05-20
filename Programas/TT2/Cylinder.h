#include <iostream>
#include <cmath>
#include "Solid.h"

using namespace std;

class Cylinder: public Solid {
    public:
        Cylinder(point center, double radius, double height): Solid(center), radius_(radius), height_(height) {}

        double radius() const { return radius_; }

        double height() const { return height_; }

        double area() const { return 2 * M_PI * radius_ * (radius_ + height_); }
    private:
        double radius_, height_;
};