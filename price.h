#ifndef PRICE_H
#define PRICE_H
#include <string>
using namespace std;

struct Price {
    int hryvnias;
    short int kopecks;
};

void add(Price& result, const Price& p1, const Price& p2);
void multiply(Price& total, int number);
void roundPrice(Price& price);
void printPrice(const Price& price, const string& label);
#endif