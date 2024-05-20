#include "Point.h"
#include <iostream>

using namespace std;

void Point::show() {
    cout << '(' << x << ',' << y << ')';
}

Point::Point(): Point(0, 0) {}

Point::Point(int x, int y): x(x), y(y) {}