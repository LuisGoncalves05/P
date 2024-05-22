#include "Figure.h"
#include <iostream>

using namespace std;

class FCircle: public Figure {
    public:
        FCircle(int x_center, int y_center, int radius): Figure(x_center, y_center), radius_(radius) {}

        void draw() const {
            cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')';
        }
    private:
        int radius_;
};