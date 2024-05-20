#include "smatrix.h"

using namespace std;

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    r = a;
    size_t idx = 0;
    for (sm_entry x: b) {
        while (true) {
            if (idx < r.size()) {
                if (x.row < r[idx].row ||
                    (x.row == r[idx].row && x.col < r[idx].col)) {
                        r.insert(r.begin() + idx, x);
                        break;
                    }
                if (x.row == r[idx].row && x.col == r[idx].col) {
                    r[idx].value += x.value;
                    break;
                }
                idx++;
            } else {
                idx++;
                r.push_back(x);
                break;
            }
        }
    }
    for (int i = 0; i < (int)r.size(); i++) {
        while (r[i].value == 0 && i < (int) r.size()) {
            for (int j = i; j < (int)r.size() - 1; j++) {
                r[j] = r[j+1];
            }
            r.pop_back();
        }
    }
}