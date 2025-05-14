#include "lambda.h"
#include <cmath>
#include <iostream>
#include <functional> 
#include <limits> 

using namespace std;

Dyhotomia::Dyhotomia(double a_, double b_, double epsilon_,
    std::function<double(double)> function_,
    std::function<double(double)> pohidna_)
    : a(a_), b(b_), epsilon(epsilon_), function(function_), pohidna(pohidna_) {}

double Dyhotomia::solveBisection() {
    if (function(a) * function(b) >= 0) {
        cerr << "Error: No root found in the given interval." << endl;
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
    double f, f_p;
    do {
        f = function(x);
        f_p = pohidna(x);
        if (fabs(f_p) < 1e-12) {
            cerr << "Error: The derivative is too small or equal to zero." << endl;
            return NAN;
        }
        x = x - f / f_p;
    } while (fabs(f) >= epsilon);
    return x;
}
