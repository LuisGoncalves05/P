#ifndef gg
#define gg

#include "Person.h"
#include <string>
#include <sstream>

using namespace std;

class Student: public Person {
    public:
        Student(int id, const string& name, const string& course): Person(id, name), course_(course) {}

        const string& course() const { return course_; }

        string to_string() const {
            ostringstream oss;
            oss << id() << '/' << name() << '/' << course_;
            return oss.str();
        }
    private:
        string course_;
};

#endif