#ifndef DYHOTOMIA_H
#define DYHOTOMIA_H

class Dyhotomia {
private:
    double a, b, epsilon;
    double function(double x);
    double pohidna(double x);

public:
    void setParameters(double a_, double b_, double epsilon_);
    double solveBisection();
    double solveNewton();
};

#endif
