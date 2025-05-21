#include "pattern1.h"
#include "pattern2.h"
#include <iostream>
#include <iomanip> // Для fixed та setprecision
using namespace std;

int main() {
    cout << "--- Demonstrating Adapter Pattern ---\n";
    cout << fixed << setprecision(2); // фіксованою комою і двома знаками після крапки

    OldFahrenheit* oldFahrenheit = new OldFahrenheit();
    ICelsiusSensor* modernCelsius = new ModernCelsius();
    ICelsiusSensor* fahrenheitAdapter = new FahrenheitToCelsiusAdapter(oldFahrenheit);

    cout << "\nUsing Modern Celsius Sensor:\n";
    cout << "Temperature: " << modernCelsius->getCelsius() << " C\n";

    cout << "\nUsing Adapter for Old Fahrenheit Sensor:\n";
    cout << "Original Fahrenheit Temperature: " << oldFahrenheit->getFahrenheit() << " F\n";
    cout << "Temperature: " << fahrenheitAdapter->getCelsius() << " C\n";

    // Очищення пам'яті
    delete oldFahrenheit;
    delete modernCelsius;
    delete fahrenheitAdapter;

    cout << "\n--- Demonstrating Builder Pattern ---\n";

    SandwichMaker maker; // Директор
    Sandwich* mySandwich;

    cout << "\n-Veggie Sandwich-\n";

    VeggieSandwichBuilder veggieBuilder;
    maker.setBuilder(&veggieBuilder);
    maker.constructSandwich();
    mySandwich = veggieBuilder.getSandwich();//повертає вже збудований об’єкт сендвіча,
    //щоб можна було викликати display
    mySandwich->displaySandwich();

    cout << "\n-Meat Sandwich-\n";

    MeatSandwichBuilder meatBuilder;
    maker.setBuilder(&meatBuilder);
    maker.constructSandwich();
    mySandwich = meatBuilder.getSandwich();
    mySandwich->displaySandwich();

    return 0;
}
