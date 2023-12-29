#include <iostream>
#include <fstream>

#include "tovar.h"

using namespace std;

void tovar::print(std::ostream& out) const
{
    data.print(out);
    out << "Название: " << name << std::endl;
    out << "Количество: " << quant << std::endl;
}

tovar tovar::read(std::istream& ist)
{
    date data;
    tovar item;
    item.data = date::read(ist);
    ist >> item.name >> item.quant;

    if (ist.fail()) {
        throw runtime_error("Invalid tovar");
    }

    return item;
}

void readDataFromFile(const std::string& filename, std::vector<tovar>& tovars) {
    std::ifstream ist(filename);
    if (!ist.is_open()) {
        std::cout << "Файл не найден";
        return;
    }

    while (!ist.eof() ) {
        // TODO: read one object
        tovar item = tovar::read(ist);
        tovars.push_back(item);
    }

    ist.close();
}

void printTovars(const std::vector<tovar>& tovars) {
    for (const tovar& t : tovars) {
        t.print(cout);
    }
}