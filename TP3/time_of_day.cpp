#include <iostream>
#include "time_of_day.h"


time_of_day tick(time_of_day t);


int main()
{
    cout << tick({ 0, 0 }) << '\n';
    //00:01
    cout << tick({ 12, 30 }) << '\n';
    //12:31
    cout << tick({ 12, 59 }) << '\n';
    //13:00
    cout << tick({ 23, 59 }) << '\n';
    //00:00
    cout << tick(tick(tick({ 23, 59 }))) << '\n';
    //00:02
    return 0;
}


time_of_day tick(time_of_day t)
{
    if (t.m == 59){
        t.m = 0;
        (t.h == 23) ? t.h = 0: t.h++;
    } else {
        t.m++;
    }
    return t;
}
