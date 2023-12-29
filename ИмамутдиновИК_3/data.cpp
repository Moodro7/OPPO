#include <vector>
#include <iostream>
#include <fstream>

#include "data.h"

using namespace std;

date is_correct_date(date data)
{
    int max_day_month = 0;
    if (data.mm == 2)
        max_day_month = (data.yyyy % 400 == 0 || (data.yyyy % 100 != 0 && data.yyyy % 4 == 0)) ? 29 : 28;
    else if (data.mm == 1 || (data.mm > 2 && data.mm <= 12))
        for (int i : {1, 3, 5, 7, 8, 10, 12})
            if (data.mm == i) {
                max_day_month = 31;
                break;
            }
            else max_day_month = 30;
    else
    {
        throw std::runtime_error("Wrong day");
    }
    if (data.dd < 1 || data.dd > max_day_month)
    {
        throw std::runtime_error("Wrong day");
    }
    return {};
}


void date::set_date(std::istream& ist, date data) {
    date::read(ist);
}

void date::print(std::ostream& out) const
{
    out << "Дата: " << yyyy << "." << mm << "." << dd << std::endl;
}

 date date::read(std::istream& ist)
{
    date data; // yyyy.mm.dd
    char dots[2];
    ist >> data.yyyy;
    //std::cout << data.yyyy;
    dots[0] = ist.get();
    ist >> data.mm;
    //std::cout << data.mm;
    dots[1] = ist.get();
    ist >> data.dd;
    //std::cout << data.dd;

    if (ist.fail()) 
        throw runtime_error("Invalid date");
    
    if (dots[0] != '.' || dots[1] != '.')
        throw runtime_error("Invalid dot");

    if (!data.is_valid(data.yyyy, data.mm, data.dd)) 
       throw runtime_error("Invalid date");
    

    //is_correct_date(data);
    //std::cout << data.dd;
    //std::cout << data.mm;

    return data;
}

