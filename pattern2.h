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

// Абстрактний клас Builder
class SandwichBuilder {
protected:
    Sandwich* sandwich; // Об'єкт, що будується

public:
    SandwichBuilder();
    virtual ~SandwichBuilder();

    Sandwich* getSandwich(); //повертає готовий сендвіч

    virtual void buildBread() = 0;
    virtual void buildFilling() = 0;
    virtual void buildSauce() = 0;
    virtual void addToppings() = 0;
};

// Конкретний Builder
class VeggieSandwichBuilder : public SandwichBuilder {
public:
    void buildBread() override;
    void buildFilling() override;
    void buildSauce() override;
    void addToppings() override;
};

// Конкретний Builder
class MeatSandwichBuilder : public SandwichBuilder {
public:
    void buildBread() override;
    void buildFilling() override;
    void buildSauce() override;
    void addToppings() override;
};

// Director (керує процесом побудови)
class SandwichMaker {
private:
    SandwichBuilder* builder;

public:
    void setBuilder(SandwichBuilder* b);//який саме будівельник
    void constructSandwich(); //викликає всі кроки будівництва по черзі
};

#endif
