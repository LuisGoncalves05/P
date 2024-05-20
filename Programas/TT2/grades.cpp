#include "Student.h"
#include <string>
#include <numeric>

using namespace std;

Student::Student(const string& id): id_(id) {}

string Student::get_id() const { return id_; }

void Student::add(const course& c) { courses_.push_back(c); }

double Student::avg() const {
    double sum = 0;
    double div = 0;
    for (const course& c: courses_) {
        sum += c.grade * c.credits;
        div += c.credits;
    }
    if (div == 0) return 0;
    return sum/div;
}