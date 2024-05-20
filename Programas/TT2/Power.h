#include "Operation.h"
#include <cmath>

using namespace std;

class Power: public Operation {
    public:
        Power(int op1, int op2): Operation(op1, op2) {}

        int operation() const {
            return pow(get_op1(), get_op2());
        }
};