#ifndef POINT_H
#define POINT_H

class Point {
    public:
        void show() const;
        Point();
        Point(int x, int y);
        int get_x() const;
        int get_y() const;
    private:
        int x_;
        int y_;
};

#endif