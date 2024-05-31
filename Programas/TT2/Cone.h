#include "Solid3D.h"
#include <cmath>

using namespace std;

class Cone: public Solid3D {
    public:
        Cone(const point& center, const double radius, const double height): Solid3D(center), radius_(radius), height_(height) {}
        double radius() const { return radius_; }
        double height() const { return height_; }
        double volume() const override {return M_PI * radius_ * radius_ * height_ / 3.0;}
    private:
        double radius_;
        double height_;
};