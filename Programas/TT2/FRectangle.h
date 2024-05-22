#include "Figure.h"
#include <iostream>

using namespace std;

class FRectangle: public Figure {
    public:
        FRectangle(int x_center, int y_center, int width, int height): Figure(x_center, y_center), width_(width), height_(height) {}

        void draw() const {
            cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ',' << height_ << ')';
        }
    private:
        int width_, height_;
};