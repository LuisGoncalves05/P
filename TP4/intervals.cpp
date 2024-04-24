#include <cmath>
#include <iostream>
#include "interval.h"


int search_intervals(time_of_day t, const interval a[], int n, interval& u);
int count_mins (time_of_day initial, time_of_day final);


int main() {
    { const int n = 1;
      const time_of_day t = { 13, 00 };
      const interval a[n] { { { 12, 30 }, { 14, 30 } } };
      interval u;
      int d = search_intervals(t, a, n, u);
      cout << d << ' ' << u << '\n'; }
    //120 [12:30,14:30[
    { const int n = 2;
      const time_of_day t = { 14, 30 };
      const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                      { { 14, 30 }, { 15, 30 } } };
      interval u;
      int d = search_intervals(t, a, n, u);
      cout << d << ' ' << u << '\n'; }
    //60 [14:30,15:30[
    { const int n = 2;
      const time_of_day t = { 12, 30 };
      const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                      { { 14, 30 }, { 15, 30 } } };
      interval u;
      int d = search_intervals(t, a, n, u);
      cout << d << ' ' << u << '\n'; }
    //120 [12:30,14:30[
    { const int n = 2;
      const time_of_day t = { 15, 30 };
      const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                      { { 14, 30 }, { 15, 30 } } };
      interval u;
      int d = search_intervals(t, a, n, u);
      cout << d << ' ' << u << '\n'; } 
    //0 [15:30,15:30[
    { const int n = 5;
      const time_of_day t = { 15, 15 };
      const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                      { { 14, 30 }, { 15, 30 } }, 
                      { { 15, 10 }, { 16, 10 } }, 
                      { {  9, 30 }, { 15, 15 } }, 
                      { {  9, 45 }, { 15, 16 } } };
      interval u;
      int d = search_intervals(t, a, n, u);
      cout << d << ' ' << u << '\n'; } 
    //385 [09:45,16:10[   
    return 0;
}


int search_intervals(time_of_day t, const interval a[], int n, interval& u)
{
    int mins = 0;
    u.start = t;
    u.end = t;
    for (int i = 0; i < n ;i++)
    {
        interval time = a[i];
        if ((t.h > time.start.h || 
        (t.h == time.start.h && t.m >= time.start.m)) &&
        (t.h < time.end.h || 
        (t.h == time.end.h && t.m < time.end.m)))
        {
            if ((time.start.h < u.start.h ||
            (time.start.h == u.start.h && time.start.m < u.start.m)) &&
            (time.end.h > u.start.h ||
            (time.end.h == u.start.h && time.end.m >= u.start.m)))
            {
                u.start = time.start;
            }
            if ((time.end.h > u.end.h ||
            (time.end.h == u.end.h && time.end.m > u.end.m)) &&
            (time.start.h < u.end.h ||
            (time.start.h == u.end.h && time.start.m <= u.end.m)))
            {
                u.end = time.end;
            }
        }
    }
    if ((u.start.h != t.h || u.start.m != t.m) || (u.end.h != t.h || u.end.m != t.m))
    {
        mins = count_mins(u.start, u.end);
    }
    return mins;
}

int count_mins (time_of_day initial, time_of_day final)
{
    int mins = 0;
    while ((initial.h < final.h) || (initial.h == final.h && initial.m < final.m))
    {
        mins++;
        if (initial.m == 59){
            initial.h++;
            initial.m = 0;
        }
        else
        {
            initial.m++;
        }
    }
    return mins;
}