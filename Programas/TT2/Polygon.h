#ifndef COIVES
#define COIVES

#include <vector>
#include "Point.h"

using namespace std;

class Polygon {
    public:
        Polygon();
        Polygon(vector<Point> points);
        bool get_vertex(int i, Point& p);
        bool add_vertex(int pos, Point vertex);
        void show();
        double perimeter();
    private:
        vector<Point> points;
};

#endif