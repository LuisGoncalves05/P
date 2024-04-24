#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
class Pair;

void show(Pair<string,int> p);

void sort_by_first(vector<Pair<string,int>> &v);

void sort_by_second(vector<Pair<string,int>> &v);

bool first_less_than_first(Pair<string,int> f, Pair<string,int> l);

bool last_less_than_last(Pair<string,int> f, Pair<string,int> l);


template <typename T, typename U>
class Pair
{
public:
    Pair(T first, U second) : first_(first), second_(second) {}
    T get_first() const { return first_; }
    U get_second() const { return second_; }

private:
    T first_;
    U second_;
};

void show(vector<Pair<string,int>> pairs) {
    cout << '{';
    for (Pair<string, int> p : pairs)
    {
        cout << '{' << p.get_first() << ',' << p.get_second() << '}';
    }
    cout << '}';
}

void sort_by_first(vector<Pair<string,int>>& v) {
    sort(v.begin(), v.end(), first_less_than_first);
}

void sort_by_second(vector<Pair<string,int>>& v){
    sort(v.begin(), v.end(), last_less_than_last);
}

bool first_less_than_first(Pair<string,int> f, Pair<string,int> l) {
    return f.get_first() < l.get_first();
}

bool last_less_than_last(Pair<string,int> f, Pair<string,int> l) {
    return f.get_second() < l.get_second();
}

int main(){
    { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
    sort_by_first(persons);
    show(persons); cout << '\n'; }
    //{{Ana,21}{Maria,17}{Pedro,19}}
    { vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
    sort_by_second(persons);
    show(persons); cout << '\n'; }
    //{{Rui,16}{Ana,19}}
    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_first(teams);
    show(teams); cout << '\n'; }
    //{{Benfica,74}{Porto,91}{Sporting,85}}
    { vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_second(teams);
    show(teams); cout << '\n'; }
    //{{Benfica,74}{Sporting,85}{Porto,91}}
    { vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
    sort_by_second(calories);
    show(calories); cout << '\n'; }
    //{{orange,37}{yogurt,51}{apple,56}{egg,146}}
    return 0;
}