#include "triangle.h"
#include <vector>
using namespace std;

int main() {

    do {
        Triangle t;
        readTriangle(t);

        if (isDegenerate(t)) {
            cout << "Degenerate triangle." << endl;
        }

        vector <Point> points; //����� points, ��� � ��������(��������� �����) � ���� �������� �������� ���� Point
        int numPoints; //�����, �� ����� �-��� �����
        cout << "Enter number of points: ";
        cin >> numPoints;

        points.resize(numPoints); //���������� ���� �� �-��� �����
        for (int i = 0; i < numPoints; ++i) {
            readPoint(points[i]);
        }

        char method;
        cout << "Use method (H) / (V) :";
        cin >> method;



      for (const auto& p : points) {
          if (method == 'V' || method == 'v') {

              if (isDegenerate(t)) {
                  if (isPointOnSegment(t.A, t.B, p) || isPointOnSegment(t.B, t.C, p) || isPointOnSegment(t.C, t.A, p)) {
                      cout << "Point (" << p.x << "; " << p.y << ") lies on the edge of the triangle." << endl;
                  }
                  else {
                      cout << "Point (" << p.x << "; " << p.y << ") does not belong to the degenerate triangle." << endl;
                  }
              }


              if (isPointInside(t, p)) {
                  double vector1 = vectorProduct(t.A, t.B, p);
                  double vector2 = vectorProduct(t.B, t.C, p);
                  double vector3 = vectorProduct(t.C, t.A, p);

                  if (isPointOnSegment(t.A, t.B, p) || isPointOnSegment(t.B, t.C, p) || isPointOnSegment(t.C, t.A, p)) {
                      cout << "Point (" << p.x << "; " << p.y << ") lies on the edge of the triangle." << endl;
                  }
                  else  if (((vector1 > epsilon && vector2 > epsilon && vector3 > epsilon) ||
                      (vector1 < -epsilon && vector2 < -epsilon && vector3 < -epsilon))) { //�������� �� ����� �� ���� �� �� �����

                      cout << "Point (" << p.x << "; " << p.y << ") belongs to a triangle." << endl;
                        }
                  else {
                      cout << "Point (" << p.x << "; " << p.y << ") does not belong to the triangle." << endl;
                  }
              }
              
          }

          if (method == 'H' || method == 'h') {
              if (isPointInsideheron(t, p)) {
                  cout << "Point (" << p.x << "; " << p.y << ") belongs to a triangle." << endl;
              }
              if (isPointOnSegment(t.A, t.B, p) || isPointOnSegment(t.B, t.C, p) || isPointOnSegment(t.C, t.A, p)) {
                  cout << "Point (" << p.x << "; " << p.y << ") lies on the edge of the triangle." << endl;
              }
              else {
                  cout << "Point (" << p.x << "; " << p.y << ") does not belong to the triangle." << endl;
              }
          }
      }
    } while (true);
   return 0;
}