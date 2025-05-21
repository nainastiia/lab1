#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include <iostream>
#include <string>

// старий інтерфейс Фаренгейта
class OldFahrenheit {
public:
    double getFahrenheit();
};

// новий інтерфейс Цельсія(абстрактний)
class ICelsiusSensor {
public:
    virtual double getCelsius() = 0;
    virtual ~ICelsiusSensor() = default;//для знищення об'єктів через вказівник на базовий клас
};

// Новий датчик, що реалізує новий інтерфейс(реалізація)
class ModernCelsius : public ICelsiusSensor {
public:
    double getCelsius() override;
};

// Адаптер: FahrenheitToCelsiusAdapter
class FahrenheitToCelsiusAdapter : public ICelsiusSensor {
private:
    OldFahrenheit* oldSensor; // Адаптований об'єкт

public:
    FahrenheitToCelsiusAdapter(OldFahrenheit* sensor); //конструктор
    double getCelsius() override;
};

#endif
