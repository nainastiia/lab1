#include "price.h"
#include <iostream>
using namespace std;

void add(Price& result, const Price& p1, const Price& p2) {
    result.hryvnias = p1.hryvnias + p2.hryvnias;
    result.kopecks = p1.kopecks + p2.kopecks;
    if (result.kopecks >= 100) {
        result.hryvnias += result.kopecks / 100;
        result.kopecks %= 100;
    }
}

void multiply(Price& total, int number) {
    Price temp = total; 
    total.hryvnias = temp.hryvnias * number;
    total.kopecks = temp.kopecks * number;
    if (total.kopecks >= 100) {
        total.hryvnias += total.kopecks / 100;
        total.kopecks %= 100;
    }
}

void roundPrice(Price& price) { 
    int ostacha = price.kopecks % 10;
    if (ostacha < 5) {
        price.kopecks -= ostacha;
    }
    else {
        price.kopecks = price.kopecks - ostacha + 10;
    }
    if (price.kopecks == 100) {
        price.hryvnias++;
        price.kopecks = 0;
    }
}

void printPrice(const Price& price, const string& label) { 
    std::cout << label << price.hryvnias << " hrn " << price.kopecks << " kop" << std::endl; 
}