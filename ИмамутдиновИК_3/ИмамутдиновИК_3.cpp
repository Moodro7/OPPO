#include "header.h"
#include <iostream>
#include <fstream>

int main()
{
    setlocale(0, "");  

    std::vector<tovar> tovars;

    readDataFromFile("in.txt", tovars);

    printTovars(tovars);
    
    return 0;
}


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


void printTovars(const std::vector<tovar>& tovars) {
    for (const tovar& t : tovars) {
        std::cout << "Дата: " << t.yyyy << "." << t.mm << "." << t.dd << std::endl;
        std::cout << "Название: " << t.name << std::endl;
        std::cout << "Количество: " << t.quant << std::endl;
    }
}





