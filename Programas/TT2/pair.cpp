#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template<class T, class P> 
class Pair {
    public:
        Pair(T one, P two): first_(one), second_(two) {}

        T get_first() { return first_; }

        P get_second() { return second_; }

        void show() {
            cout <<'{' << first_ << ',' << second_ << '}';
        }
    private:
        T first_;
        P second_;
};

template<class T, class P>
void sort_by_first(vector<Pair<T, P>>& v) {
    sort(v.begin(), v.end(), [](Pair<T,P> p0, Pair<T,P> p1){ return p0.get_first()< p1.get_first(); });
}

template<class T, class P>
void sort_by_second(vector<Pair<T, P>>& v) {
    sort(v.begin(), v.end(), [](Pair<T,P> p0, Pair<T,P> p1){ return p0.get_second() < p1.get_second(); });
}

template<class T, class P>
void show(vector<Pair<T, P>> v) {
    cout << '{';
    for (Pair<T, P> p: v) {
        p.show();
    }
    cout << '}';
}