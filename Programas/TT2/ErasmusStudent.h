#ifndef cul
#define cul

#include "Student.h"
#include <string>
#include <sstream>

using namespace std;

class ErasmusStudent: public Student {
    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country): Student(id, name, course), country_(country) {}

        const string& country() const { return country_; }
        
        string to_string() const {
            ostringstream oss;
            oss << id() << '/' << name() << '/' << course() << '/' << country_;
            return oss.str();
        }
    private:
        string country_;
};

#endif