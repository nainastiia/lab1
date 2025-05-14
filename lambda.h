#ifndef LAMBDA_H
#define LAMBDA_H
#include <functional> //для std::
#include <string>
#include <iostream>

class Dyhotomia {
private:
    double a, b, epsilon;
    std::function<double(double)> function; //оголошення змінної function, 
    //яка може зберігати будь-яку функцію, лямбда-вираз
    std::function<double(double)> pohidna; 

public:
    Dyhotomia(double a_, double b_, double epsilon_,
        std::function<double(double)> function_,
        std::function<double(double)> pohidna_ ); // конструктор для ініціалізації параметрів та функцій

    double solveBisection();
    double solveNewton();
};

#endif 