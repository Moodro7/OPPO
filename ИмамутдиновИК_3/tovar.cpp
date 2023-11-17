#include "tovar.h"
#include <iostream>

void printTovars(const std::vector<tovar>& tovars) {
    for (const tovar& t : tovars) {
        std::cout << "Дата: " << t.yyyy << "." << t.mm << "." << t.dd << std::endl;
        std::cout << "Название: " << t.name << std::endl;
        std::cout << "Количество: " << t.quant << std::endl;
    }
}

