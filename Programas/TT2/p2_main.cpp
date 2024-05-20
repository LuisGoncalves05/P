#include <vector>
#include "Date.h"
#include "Person.h"

void born_before(const vector<Person>& persons, const Date& date) {
    date.show();
    cout << ':';
    for (Person p: persons) {
        Date D;
        if (D.is_before(date)) {
            cout << ' ' << p.get_name() << '-';
            D.show();
        }
    }
}