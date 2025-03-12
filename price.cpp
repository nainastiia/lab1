#include "price.h"
#include <iostream>
using namespace std;

void add(Price& p, int hryvnias, short int kopecks) {
    p.hryvnias += hryvnias;
    p.kopecks += kopecks;
    if (p.kopecks >= 100) {
        p.hryvnias += p.kopecks / 100;
        p.kopecks %= 100;
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