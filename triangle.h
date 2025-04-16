#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
};

extern const double epsilon; //константа з плаваючою комою подвійної точності, щоб була доступна у всіх файлах

double distance(const Point& p1, const Point& p2);
double vectorProduct(const Point& p1, const Point& p2, const Point& p3);
double triangleArea(const Triangle& t);
bool isDegenerate(const Triangle& t);
bool isPointInside(const Triangle& t, const Point& p);
bool isPointOnSegment(const Point& a, const Point& b, const Point& p);
void readPoint(Point& p);
void readTriangle(Triangle& t);
double heronArea(const Triangle& t);
bool isPointInsideheron(const Triangle& t, const Point& p);

#endif 
