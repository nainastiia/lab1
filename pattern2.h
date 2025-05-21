#ifndef SANDWICH_BUILDER_H
#define SANDWICH_BUILDER_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Sandwich {
public:
    string bread;
    string filling;
    string sauce;
    vector<string> toppings;

    void addTopping(const string& topping);
    void displaySandwich() const;
};

// ����������� ���� Builder
class SandwichBuilder {
protected:
    Sandwich* sandwich; // ��'���, �� ��������

public:
    SandwichBuilder();
    virtual ~SandwichBuilder();

    Sandwich* getSandwich(); //������� ������� ������

    virtual void buildBread() = 0;
    virtual void buildFilling() = 0;
    virtual void buildSauce() = 0;
    virtual void addToppings() = 0;
};

// ���������� Builder
class VeggieSandwichBuilder : public SandwichBuilder {
public:
    void buildBread() override;
    void buildFilling() override;
    void buildSauce() override;
    void addToppings() override;
};

// ���������� Builder
class MeatSandwichBuilder : public SandwichBuilder {
public:
    void buildBread() override;
    void buildFilling() override;
    void buildSauce() override;
    void addToppings() override;
};

// Director (���� �������� ��������)
class SandwichMaker {
private:
    SandwichBuilder* builder;

public:
    void setBuilder(SandwichBuilder* b);//���� ���� ����������
    void constructSandwich(); //������� �� ����� ���������� �� ����
};

#endif
