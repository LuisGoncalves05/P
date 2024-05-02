#include "MovingAverage.h"
#include <iostream>
#include <iomanip>

int main() {
    
    return 0;
}


MovingAverage::MovingAverage(std::size_t n) : n_(n){}

void MovingAverage::update(double value) {
    if (values_.size() == n_) {
        values_.pop_back();
    }
    values_.push_front(value);
}

double MovingAverage::get() const {
    double res = 0;
    for (double val: values_) {
        res += val;
    }
    res /= values_.size();
    return res;
}
