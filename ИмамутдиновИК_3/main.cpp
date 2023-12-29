
#include "data.h"
#include "tovar.h"
#include <iostream>
#include <fstream>

int main()
{
    setlocale(0, "");

    std::vector<tovar> tovars;
    try {
        readDataFromFile("in.txt", tovars);

        printTovars(tovars);
    }
    catch (std::exception& err) {
        std::cerr << err.what();
    }


    return 0;
}