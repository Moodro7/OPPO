#include "tovar.h"
#include <iostream>

void printTovars(const std::vector<tovar>& tovars) {
    for (const tovar& t : tovars) {
        std::cout << "����: " << t.yyyy << "." << t.mm << "." << t.dd << std::endl;
        std::cout << "��������: " << t.name << std::endl;
        std::cout << "����������: " << t.quant << std::endl;
    }
}

