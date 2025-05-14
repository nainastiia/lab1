#include <iostream>
#include "lambda.h"

using namespace std;

int main() {
    auto f = [](double x)-> double { 
        return x - 1.0 / (3.0 - sin(3.6 * x)); //лямбда-функція, яка обчислює значення функції
    };

    auto f_pohidna = [f](double x) {
        double dx = 1e-6;
        return (f(x + dx) - f(x)) / dx; //лямбда-функція, яка обчислює похідну від f
    };

    Dyhotomia dyh(0.0, 0.8, 1e-6, f, f_pohidna);

    cout << "Bisection method: x = " << dyh.solveBisection() << endl;
    cout << "Newton's method: x = " << dyh.solveNewton() << endl;

    return 0;
}