#include "romb.h"
#include <iostream>

using namespace std;

int Clothing::SetColor(const string& c) {
    color = c;
    return 1;
}

int Clothing::SetSize(const string& s) {
    size = s;
    return 1;
}

void Clothing::Describe() {
    cout << "Clothing: Color = " << color << ", Size = " << size << endl;
}

int Clothing::CreateClothingInternal() {
    cout << "Clothing created with size " << size << ", color " << color << " .\n";
    return 1;
}

Shirt::Shirt(const string& c, const string& s) : Clothing(c, s) {
    cout << "Shirt created.\n";
}
void Shirt::Describe() {
    cout << "Shirt: Color = " << color << ", Size = " << size <<  endl;
}

Pants::Pants(const string& c, const string& s) : Clothing(c, s) {
    cout << "Pants created.\n";
}
void Pants::Describe() {
    cout << "Pants: Color = " << color << ", Size = " << size <<  endl;
}

Jacket::Jacket(const string& c, const string& s) : Clothing(c, s) {
    cout << "Jacket created.\n";
}
void Jacket::Describe() {
    cout << "Jacket: Color = " << color << ", Size = " << size <<  endl;
}

DesignerShirt::DesignerShirt(const string& c, const string& s, const string& b)
    : Shirt(c, s), brand(b) {
    cout << "added brand: " << brand << "\nWe have a designer shirt!\n\n";
}
void DesignerShirt::Describe() {
    cout << "Designer Shirt: Brand = " << brand << ", Color = " << color
        << ", Size = " << size << "\n";
}

CasualJacket::CasualJacket(const string& c, const string& s, bool hood)
    : Jacket(c, s), hasHood(hood) {
    cout << "added hood: " << (hasHood ? "yes" : "no") << "\nWe have a casual jacket!\n\n";
}
void CasualJacket::Describe() {
    cout << "Casual Jacket: " << (hasHood ? "With Hood" : "No Hood")
        << ", Color = " << color << ", Size = " << size << "\n";
}

MultiFeatureItem::MultiFeatureItem(const string& c, const string& s, const string& f)
    : Shirt(c, s), Pants(c, s), Jacket(c, s), feature(f) {
    cout << "added feature: " << feature << "\nWe have a multi-feature item!\n\n";
}
void MultiFeatureItem::Describe() {
    cout << "MultiFeatureItem: Color = " <<Shirt:: color << ", Size = " <<Pants:: size <<  ", Feature = " << feature << "\n";
}