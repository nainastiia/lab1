#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include <iostream>
#include <string>

// ������ ��������� ����������
class OldFahrenheit {
public:
    double getFahrenheit();
};

// ����� ��������� ������(�����������)
class ICelsiusSensor {
public:
    virtual double getCelsius() = 0;
    virtual ~ICelsiusSensor() = default;//��� �������� ��'���� ����� �������� �� ������� ����
};

// ����� ������, �� ������ ����� ���������(���������)
class ModernCelsius : public ICelsiusSensor {
public:
    double getCelsius() override;
};

// �������: FahrenheitToCelsiusAdapter
class FahrenheitToCelsiusAdapter : public ICelsiusSensor {
private:
    OldFahrenheit* oldSensor; // ����������� ��'���

public:
    FahrenheitToCelsiusAdapter(OldFahrenheit* sensor); //�����������
    double getCelsius() override;
};

#endif
