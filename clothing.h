#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
using namespace std;

class Clothing {
protected:
    string color;
    string size;
    string material;
    int CreateClothing();

public:
    int SetColor(const string& c);
    int SetSize(const string& s);
    int SetMaterial(const string& m);
    virtual void Describe(); //дозволяє нащадкам по-різному реагувати на виклик методу
};

class Shirt : public Clothing { //публічно успадковується від класу Clothing
public:
    Shirt(const string& c, const string& s, const string& m);//конструктор
    void Describe() override; //перевизначення віртуального методу
};

class Pants : public Clothing {
public:
    Pants(const string& c, const string& s, const string& m);
    void Describe() override;
};

class Jacket : public Clothing {
public:
    Jacket(const string& c, const string& s, const string& m);
    void Describe() override;
};

class DesignerShirt : public Shirt {
protected:
    string brand;

public:
    DesignerShirt(const string& c, const string& s, const string& m, const string& b);
    void Describe() override;
};

class CasualJacket : public Jacket {
protected:
    bool hasHood;

public:
    CasualJacket(const string& c, const string& s, const string& m, bool hood);
    void Describe() override;
};

#endif

