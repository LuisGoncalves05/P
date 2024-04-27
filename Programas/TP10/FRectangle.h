#ifndef FRECTANGLE_H
#define FRECTANGLE_H

#include "Figure.h"

class FRectangle: public Figure {
    public:
        FRectangle(double x_center = 0, double y_center = 0, double width = 0, double height = 0) : Figure(x_center, y_center), width_(width), height_(height) {}
        void draw() const {
            std::cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ',' << height_ << ')';
        }
    private : 
        double width_;
        double height_;
};

#endif