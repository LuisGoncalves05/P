#include "interval.h"


interval intersection(interval a, interval b);
bool bigger(time_of_day a, time_of_day b);


int main()
{
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n';
    //[00:00,00:00[
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                          { { 14, 30 }, { 18, 30 } } ) << '\n';
    //[00:00,00:00[
    cout << intersection( { { 12, 30 }, { 14, 31 } },
                          { { 14, 30 }, { 18, 30 } } ) << '\n';
    //[14:30,14:31[
    cout << intersection( { { 14, 30 }, { 15, 59 } },
                          { { 11, 30 }, { 14, 31 } } ) << '\n';
    //[14:30,14:31[
    cout << intersection( { {  4, 30 }, {  7, 59 } },
                          { {  4,  0 }, {  7, 29 } } ) << '\n';
    //[04:30,07:29[
    cout << intersection( { { 23,  0 }, { 23, 58 } },
                          { { 22, 45 }, { 23, 59 } } ) << '\n';
    //[23:00,23:58[
    cout << intersection( { { 17,  0 }, { 19,  0 } },
                          { { 15,  0 }, { 17,  0 } } ) << '\n';
    //[00:00,00:00[
    return 0;
}


interval intersection(interval a, interval b)
{
    interval res = {{0,0}, {0,0}};
    if (bigger(a.start, b.start) && bigger(b.end, a.start))
    {
        if (bigger(a.end, b.start))
        {   
            res.start = a.start;
            if (bigger(b.end, a.end))
            {
                res.end = a.end;
            }
            else
            {
                res.end = b.end;
            }
        }
    }
    else if (bigger(b.start, a.start) && bigger(a.end, b.start))
    {
        if (bigger(b.end, a.start))
        {   
            res.start = b.start;
            if (bigger(a.end, b.end))
            {
                res.end = b.end;
            }
            else
            {
                res.end = a.end;
            }
        }
    }
    return res;
}

bool bigger(time_of_day a, time_of_day b)
{
    return (a.h > b.h || (a.h == b.h && a.m > b.m));
}