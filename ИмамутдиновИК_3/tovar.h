#ifndef TOVAR_H
#define TOVAR_H

#include "Header.h"
#include "data.h"
#include <iostream>
#include <string>

struct tovar {
    date data;
    std::string name;
    int quant;

    void print(std::ostream& out) const;
    tovar read(std::istream& ist);
};

void printTovars(const std::vector<tovar>& tovars);

#endif
