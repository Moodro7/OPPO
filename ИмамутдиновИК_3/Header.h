#ifndef HEADER_H  
#define HEADER_H

#include <string>
#include <vector>


struct tovar {
    int yyyy, mm, dd;   
    std::string name;   
    int quant;         
};

void readDataFromFile(const std::string& filename, std::vector<tovar>& tovars);
void printTovars(const std::vector<tovar>& tovars);

#endif  
