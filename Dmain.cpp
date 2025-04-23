#include <iostream>
#include "Dyhotomia.h"
using namespace std;

int main() {
    Dyhotomia* dyh = new Dyhotomia();
    dyh->setParameters(0.0, 0.8, 1e-6);

    cout << "Bisection method: x = " << dyh->solveBisection() << endl;
    cout << "Newton's method: x = " << dyh->solveNewton() << endl;

    delete dyh;
    return 0;
}
