#include "data.h"
#include "tovar.h"
#include "Header.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void readDataFromFile(const std::string& filename, std::vector<tovar>& tovars) {
    std::ifstream ist(filename);
    if (!ist.is_open()) {
        std::cout << "Файл не найден";
        return;
    }

    tovar item;
    while (!ist.eof()) {
        tovars.push_back(item);
    }

    ist.close();
}

void date::print(std::ostream& out, date data) const
{
    std::cout << "Дата: " << data.yyyy << "." << data.mm << "." << data.dd << std::endl;
}

static date read(std::istream& ist)
{
    date data;
    ist >> data.yyyy;
    ist.get();
    ist >> data.mm;
    ist.get();
    ist >> data.dd;
    ist.get();
    ist.get();
    return data;
}
