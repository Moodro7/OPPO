#include "data.h"
#include "tovar.h"
#include <iostream>
#include <fstream>

void readDataFromFile(const std::string& filename, std::vector<tovar>& tovars) {
    std::ifstream ist(filename);
    if (!ist.is_open()) {
        std::cout << "Файл не найден";
        return;
    }

    tovar item;
    while (!ist.eof()) {
        ist >> item.yyyy;
        ist.get();
        ist >> item.mm;
        ist.get();
        ist >> item.dd;
        ist.get();
        ist >> item.name >> item.quant;
        tovars.push_back(item);
    }
    ist.close();
}
