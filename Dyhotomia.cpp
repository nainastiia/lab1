#include "Dyhotomia.h"
#include <cmath>
#include <iostream>
using namespace std;

double Dyhotomia::function(double x) {
    return x - 1.0 / (3.0 - sin(3.6 * x));
}

double Dyhotomia::pohidna(double x) {
    double dx = 1e-6;
    return (function(x + dx) - function(x)) / dx;
}

void Dyhotomia::setParameters(double a_, double b_, double epsilon_) {
    a = a_;
    b = b_;
    epsilon = epsilon_;
}

double Dyhotomia::solveBisection() {
    if (function(a) * function(b) >= 0) {
        cerr << "No root found in the given interval." << endl;
        return NAN;
    }

    double c;
    while ((b - a) >= epsilon) { 
        c = (a + b) / 2;
        if (function(c) == 0.0)
            break;
        else if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

double Dyhotomia::solveNewton() {
    double x = (a + b) / 2;
    double f, f_der;
    do {
        f = function(x);
        f_der = pohidna(x);
        if (fabs(f_der) < 1e-12) {
            cerr << "The derivative is too small or equal to zero." << endl;
            return NAN;
        }
        x = x - f / f_der;
    } while (fabs(f) >= epsilon);
    return x;
}

