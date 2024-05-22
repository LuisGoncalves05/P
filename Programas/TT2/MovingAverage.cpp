#include "MovingAverage.h"
#include <vector>
#include <algorithm>

using namespace std;

MovingAverage::MovingAverage(std::size_t n): n_(n) {}

void MovingAverage::update(double value) {
    if (n_ == values_.size()) {
        values_.pop_front();
    }
    values_.push_back(value);
    
}

double MovingAverage::get() const {
    double acc = 0;
    auto elem = values_.begin();
    for (int i = 0; i < (int) min(values_.size(), n_); i++) {
        acc += *elem;
        elem++;
    }
    return acc / min(values_.size(), n_);
}
