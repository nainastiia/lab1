#include "pattern1.h"
#include "pattern2.h"
#include <iostream>
#include <iomanip> // ��� fixed �� setprecision
using namespace std;

int main() {
    cout << "--- Demonstrating Adapter Pattern ---\n";
    cout << fixed << setprecision(2); // ���������� ����� � ����� ������� ���� ������

    OldFahrenheit* oldFahrenheit = new OldFahrenheit();
    ICelsiusSensor* modernCelsius = new ModernCelsius();
    ICelsiusSensor* fahrenheitAdapter = new FahrenheitToCelsiusAdapter(oldFahrenheit);

    cout << "\nUsing Modern Celsius Sensor:\n";
    cout << "Temperature: " << modernCelsius->getCelsius() << " C\n";

    cout << "\nUsing Adapter for Old Fahrenheit Sensor:\n";
    cout << "Original Fahrenheit Temperature: " << oldFahrenheit->getFahrenheit() << " F\n";
    cout << "Temperature: " << fahrenheitAdapter->getCelsius() << " C\n";

    // �������� ���'��
    delete oldFahrenheit;
    delete modernCelsius;
    delete fahrenheitAdapter;

    cout << "\n--- Demonstrating Builder Pattern ---\n";

    SandwichMaker maker; // ��������
    Sandwich* mySandwich;

    cout << "\n-Veggie Sandwich-\n";

    VeggieSandwichBuilder veggieBuilder;
    maker.setBuilder(&veggieBuilder);
    maker.constructSandwich();
    mySandwich = veggieBuilder.getSandwich();//������� ��� ���������� �ᒺ�� �������,
    //��� ����� ���� ��������� display
    mySandwich->displaySandwich();

    cout << "\n-Meat Sandwich-\n";

    MeatSandwichBuilder meatBuilder;
    maker.setBuilder(&meatBuilder);
    maker.constructSandwich();
    mySandwich = meatBuilder.getSandwich();
    mySandwich->displaySandwich();

    return 0;
}
