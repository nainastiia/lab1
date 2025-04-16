#include "triangle.h"
using namespace std;
const double epsilon = 1e-4;

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double vectorProduct(const Point& p1, const Point& p2, const Point& p3) { 
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x); //формула векторного добутку в двовимірному просторі
}

double triangleArea(const Triangle& t) {
    return 0.5 * fabs(vectorProduct(t.A, t.B, t.C)); // fabs це модуль з числа
}

bool isDegenerate(const Triangle& t) {   //якщо <, то трикутник вироджений
    return triangleArea(t) < epsilon;
}

bool isPointOnSegment(const Point& a, const Point& b, const Point& p) {
    if (fabs(vectorProduct(a, b, p)) > epsilon) return false;
    return (p.x >= fmin(a.x, b.x) - epsilon && p.x <= fmax(a.x, b.x) + epsilon &&
        p.y >= fmin(a.y, b.y) - epsilon && p.y <= fmax(a.y, b.y) + epsilon);
}

bool isPointInside(const Triangle& t, const Point& p) {
    if (isDegenerate(t)) {
        return (fabs(p.x - t.A.x) < epsilon && fabs(p.y - t.A.y) < epsilon); //перевірка чи x і y близько до вершини
    }

    double vector1 = vectorProduct(t.A, t.B, p); //векторний добуток між 2 вершинами і точкою яку задали
    double vector2 = vectorProduct(t.B, t.C, p);
    double vector3 = vectorProduct(t.C, t.A, p);
    
    if (isPointOnSegment(t.A, t.B, p) || isPointOnSegment(t.B, t.C, p) || isPointOnSegment(t.C, t.A, p)) {
        return true; // Точка лежить на межі трикутника
    }

    if (((vector1 > epsilon && vector2 > epsilon && vector3 > epsilon) ||
        (vector1 < -epsilon && vector2 < -epsilon && vector3 < -epsilon))) {
        return true; // Точка всередині трикутника
    }

    return false;
}

bool isPointInsideheron(const Triangle& t, const Point& p) {
    if (heronArea(t) < epsilon) { // Враховуємо можливу близькість до виродженого
        return isPointOnSegment(t.A, t.B, p) || isPointOnSegment(t.B, t.C, p) || isPointOnSegment(t.C, t.A, p);
    }

    Triangle t1 = { p, t.B, t.C };
    Triangle t2 = { t.A, p, t.C };
    Triangle t3 = { t.A, t.B, p };

    double area1 = heronArea(t1);
    double area2 = heronArea(t2);
    double area3 = heronArea(t3);

    return fabs(area1 + area2 + area3 - heronArea(t)) < epsilon;
}
void readPoint(Point& p) {
    cout << "Enter x: ";
    cin >> p.x;
    cout << "Enter y: ";
    cin >> p.y;
}

void readTriangle(Triangle& t) {
    cout << "Enter the coordinates of the triangle A.x : ";
    cin >> t.A.x;
    cout << "Enter the coordinates of the triangle A.y : ";
    cin >> t.A.y;
    cout << "Enter the coordinates of the triangle B.x : ";
    cin >> t.B.x;
    cout << "Enter the coordinates of the triangle B.y : ";
    cin >> t.B.y;
    cout << "Enter the coordinates of the triangle C.x : ";
    cin >> t.C.x;
    cout << "Enter the coordinates of the triangle C.y : ";
    cin >> t.C.y;
}