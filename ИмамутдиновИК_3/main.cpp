#include "Header.h"
#include "data.h"
#include "tovar.h"
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







