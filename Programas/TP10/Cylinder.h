#include "Solid.h"

class Cylinder: public Solid
{
    public:
        Cylinder(point center, double radius, double height)
        : Solid(center), radius_(radius), height_(height)
        {}
        double radius() const { return radius_; }
        double height() const { return height_; }
        double area() const 
        {
            return M_PI * 2 * radius_ * (radius_ + height_); 
        }

    private:
        double radius_;
        double height_;
};