#include "tovar.h"
#include <iostream>
using namespace std;

void printTovars(const std::vector<tovar>& tovars) {
    for (const tovar& t : tovars) {
        t.print(cout);
    }
}

void tovar::print(std::ostream& out) const
{
    data.print(out, data);
    out << "��������: " << name << std::endl;
    out << "����������: " << quant << std::endl;
}

tovar tovar::read(std::istream& ist)
{
    tovar item;
    date::read(ist);
    ist >> item.name >> item.quant;
    return item;
}