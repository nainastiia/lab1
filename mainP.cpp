#include <iostream>
#include <fstream>
#include "price.h"
using namespace std;

int main() {
    Price total{ 0, 0 };
    ifstream file("C:\\Users\\Анастасія\\Desktop\\TextFile1.txt"); 
    if (!file) {
        cerr << "Error opening file" << endl; 
        return 1;
    }

    int hryvnias, number;
    short int kopecks;
    Price tempPrice;

    while (file >> hryvnias >> kopecks >> number) {
        cout << "Information: " << hryvnias << " " << kopecks << " " << number << endl; 
        tempPrice = { hryvnias, kopecks };
        multiply(tempPrice, number);
        Price priceAdd = { tempPrice.hryvnias, tempPrice.kopecks };
        add(total, total, priceAdd);
    }

    printPrice(total, "Total price: "); 

    roundPrice(total); 

    printPrice(total, "Rounded price: "); 

    return 0;
}