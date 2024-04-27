#ifndef FCIRCLE_H
#define FCIRCLE_H

#include "Figure.h"

class FCircle: public Figure {
    public:
        FCircle(double x_center = 0, double y_center = 0, double radius = 0) : Figure(x_center, y_center), radius_(radius) 
        {}
        void draw() const {
            std::cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')';
        }
    private:
        double radius_;
};

#endif