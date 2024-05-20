#ifndef POTATO
#define POTATO

using namespace std;

class Point {
    friend class Polygon;
    public:
        Point();
        Point(int x, int y);
        void show();
    private:
        int x, y;
};

#endif