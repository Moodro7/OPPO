#ifndef DATA_H
#define DATA_H

#include <vector>
#include <iostream>

using namespace std;

struct date {
    int yyyy, mm, dd;

    void print(std::ostream& out) const;
    static date read(std::istream& ist);
    void set_date(std::istream& ist, date data);

    //is_valid()
    static bool is_valid(int yyyy, int mm, int dd) {
        int max_day_month = 0;
        if (mm == 2)
            max_day_month = (yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy % 4 == 0)) ? 29 : 28;
        else if (mm == 1 || (mm > 2 && mm <= 12))
            for (int i : {1, 3, 5, 7, 8, 10, 12})
                if (mm == i) {
                    max_day_month = 31;
                    break;
                }
                else max_day_month = 30;
        else
            return false;
        if (dd < 1 || dd > max_day_month)
            return false;

        return true;
    }

    
    //דדדד.לל.הה
};

#endif