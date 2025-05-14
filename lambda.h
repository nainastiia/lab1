#ifndef LAMBDA_H
#define LAMBDA_H
#include <functional> //��� std::
#include <string>
#include <iostream>

class Dyhotomia {
private:
    double a, b, epsilon;
    std::function<double(double)> function; //���������� ����� function, 
    //��� ���� �������� ����-��� �������, ������-�����
    std::function<double(double)> pohidna; 

public:
    Dyhotomia(double a_, double b_, double epsilon_,
        std::function<double(double)> function_,
        std::function<double(double)> pohidna_ ); // ����������� ��� ����������� ��������� �� �������

    double solveBisection();
    double solveNewton();
};

#endif 