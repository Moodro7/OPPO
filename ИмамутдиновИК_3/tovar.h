#ifndef TOVAR_H
#define TOVAR_H

#include "Header.h"

struct tovar {
    int yyyy, mm, dd;
    std::string name;
    int quant;
};

void printTovars(const std::vector<tovar>& tovars);
#endif
