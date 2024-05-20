#include "Shape.h"
#include <cmath>

using namespace std;

class Circle: public Shape {
    public:
        Circle(const point& center, double radius): Shape(center), radius_(radius) {}

        double area() const {
            return M_PI * radius_ * radius_;
        }

        double perimeter() const {
            return (2 * M_PI * radius_);
        }

        bool contains(const point& p) const {
            return (sqrt(pow(p.x - get_center().x,2) + pow(p.y - get_center().y,2)) <= radius_);
        }

    private:
        double radius_;
};