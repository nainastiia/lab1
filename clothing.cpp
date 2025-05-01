#include "clothing.h"
#include <iostream>
using namespace std;

int Clothing::SetColor(const string& c) {
    color = c;
    return 1; //успішно
}

int Clothing::SetSize(const string& s) {
    size = s;
    return 1;
}

int Clothing::SetMaterial(const string& m) {
    material = m;
    return 1;
}

void Clothing::Describe() {
    cout << "Clothing: Color = " << color << ", Size = " << size << ", Material = " << material << endl;
}

int Clothing::CreateClothing() {
    cout << "Clothing created with size " << size << ", color " << color << " and material " << material << ".\n";
    return 1;
}

Shirt::Shirt(const string& c, const string& s, const string& m) {
    SetColor(c);
    SetSize(s);
    SetMaterial(m);
    CreateClothing();
}
void Shirt::Describe() {
    cout << "Shirt: Color = " << color << ", Size = " << size << ", Material = " << material << endl;
}

Pants::Pants(const string& c, const string& s, const string& m) {
    SetColor(c);
    SetSize(s);
    SetMaterial(m);
    CreateClothing();
}
void Pants::Describe() {
    cout << "Pants: Color = " << color << ", Size = " << size << ", Material = " << material << endl;
}

Jacket::Jacket(const string& c, const string& s, const string& m) {
    SetColor(c);
    SetSize(s);
    SetMaterial(m);
    CreateClothing();
}
void Jacket::Describe() {
    cout << "Jacket: Color = " << color << ", Size = " << size << ", Material = " << material << endl;
}

DesignerShirt::DesignerShirt(const string& c, const string& s, const string& m, const string& b)
    : Shirt(c, s, m), brand(b) {} //виклик конструктора базового класу Shirt
void DesignerShirt::Describe() {
    cout << "Designer Shirt: Brand = " << brand << ", Color = " << color
        << ", Size = " << size << ", Material = " << material << endl;
}

CasualJacket::CasualJacket(const string& c, const string& s, const string& m, bool hood)
    : Jacket(c, s, m), hasHood(hood) {} //виклик конструктора базового класу Jacket
void CasualJacket::Describe() {
    cout << "Casual Jacket: " << (hasHood ? "With Hood" : "No Hood")//тернарний
        << ", Color = " << color << ", Size = " << size << ", Material = " << material << endl;
}
