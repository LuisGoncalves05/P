#include <vector>
#include "Person.h"
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

Person::Person(const string& name, const string& address, const string& phone): name_(name), address_(address), phone_(phone) {}

string Person::get_name() const {
    return name_;
}

string Person::get_address() const {
    return address_;
}

string Person::get_phone() const {
    return phone_;
}

void read_persons_data(const string& file_name, vector<Person>& persons) {
    ifstream ifs(file_name);
        string name;
        string address;
        string phone;
    while (getline(ifs, name) && getline(ifs, address) && getline(ifs, phone)) {
        persons.push_back({name, address, phone});
    }
}

void sort_persons_by_name(vector<Person>& persons) {
    sort(persons.begin(), persons.end(), [](Person p1, Person p2) {return p1.get_name() < p2.get_name();});
}