#include "pattern1.h"
using namespace std;

double OldFahrenheit::getFahrenheit() {
    // Імітація отримання температури у Фаренгейтах
    return 72.0; 
}

double ModernCelsius::getCelsius() {
    // Імітація отримання температури у Цельсіях
    return 36.6;
}

// Адаптер
FahrenheitToCelsiusAdapter::FahrenheitToCelsiusAdapter(OldFahrenheit* sensor) : oldSensor(sensor) {
    cout << "Fahrenheit To Celsius Adapter: Created adapter for OldFahrenheitSensor.\n";
}

double FahrenheitToCelsiusAdapter::getCelsius() {
    cout << "Adapter: Converting temperature from Fahrenheit to Celsius.\n";
    double fahrenheit = oldSensor->getFahrenheit(); //оператор доступу через вказівник
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
