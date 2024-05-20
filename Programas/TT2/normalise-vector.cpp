#include <vector>
#include <algorithm>
#include "print_vector.h"

using namespace std;

template <typename T>
void normalise(vector<T> &v, const T &min, const T &max) {
    for_each(v.begin(), v.end(),
             [max, min] (T& elem) -> void
             {elem = elem < min? min: (elem > max? max: elem);});
}