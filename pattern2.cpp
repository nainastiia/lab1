#include "pattern2.h"
using namespace std;

void Sandwich::addTopping(const string& topping) {
    toppings.push_back(topping);
}

void Sandwich::displaySandwich() const {
    cout << "Sandwich Configuration:\n";
    cout << "  Bread: " << bread << "\n";
    cout << "  Filling: " << filling << "\n";
    cout << "  Sauce: " << sauce << "\n";
    cout << "  Toppings: ";
    if (toppings.empty()) {
        cout << "None\n";
    }
    else {
        for (const auto& topping : toppings) {
            cout << topping << " ";
        }
        cout << "\n";
    }
}

// Абстрактний клас Builder
SandwichBuilder::SandwichBuilder() : sandwich(new Sandwich()) {}
SandwichBuilder::~SandwichBuilder() { delete sandwich; }
Sandwich* SandwichBuilder::getSandwich() { return sandwich; }

// Конкретний Builder
void VeggieSandwichBuilder::buildBread() { sandwich->bread = "Whole Wheat Bread"; }
void VeggieSandwichBuilder::buildFilling() { sandwich->filling = "Grilled Vegetables"; }
void VeggieSandwichBuilder::buildSauce() { sandwich->sauce = "Pesto"; }
void VeggieSandwichBuilder::addToppings() {
    sandwich->addTopping("Lettuce");
    sandwich->addTopping("Tomatoes");
    sandwich->addTopping("Cucumbers");
}

// Конкретний Builder: MeatSandwichBuilder
void MeatSandwichBuilder::buildBread() { sandwich->bread = "White Baguette"; }
void MeatSandwichBuilder::buildFilling() { sandwich->filling = "Ham and Cheese"; }
void MeatSandwichBuilder::buildSauce() { sandwich->sauce = "Ketchup"; }
void MeatSandwichBuilder::addToppings() {
    sandwich->addTopping("Pickles");
    sandwich->addTopping("Cheese");
    sandwich->addTopping("Onion");
}

// Director: SandwichMaker (Виробник сендвічів)
void SandwichMaker::setBuilder(SandwichBuilder* b) { builder = b; }
void SandwichMaker::constructSandwich() {
    builder->buildBread();
    builder->buildFilling();
    builder->buildSauce();
    builder->addToppings();
}
