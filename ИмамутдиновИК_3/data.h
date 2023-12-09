#ifndef DATA_H
#define DATA_H

#include "Header.h"
#include "tovar.h"
#include<vector>
using namespace std;

struct date {
    int yyyy, mm, dd;
    void print(std::ostream& out, date data) const;
    static date read(std::istream& ist);
};

void readDataFromFile(const std::string& filename, std::vector<tovar>& tovars);

#endif