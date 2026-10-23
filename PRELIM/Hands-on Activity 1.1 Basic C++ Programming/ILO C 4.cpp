#include<iostream>
#include<cmath>
using namespace std;

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C, double a, double b, double c);
    void setValues(double A, double B, double C, double a, double b, double c);
    bool validateTriangle();
    double getPerimeter();
    double getArea();
    void triangleType();

};

Triangle::Triangle(double A, double B, double C, double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = a;
    sideB = b;
    sideC = c;
    
}

void Triangle::setValues(double A, double B, double C, double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = a;
    sideB = b;
    sideC = c;
}

bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

double Triangle::getPerimeter() {
    return sideA + sideB + sideC;
}
void Triangle::triangleType() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        cout << "The triangle is an acute triangle." << endl;
    } else if (angleA == 90 || angleB == 90 || angleC == 90) {
        cout << "The triangle is a right triangle." << endl;
    } else {
        cout << "The triangle is an obtuse triangle." << endl;
    }
}

int main() {
    Triangle set1(40, 30, 110, 8, 7, 5);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle." << endl;
        cout << "Perimeter of the triangle: " << set1.getPerimeter() << endl;
        set1.triangleType();
    } else {
        cout << "The shape is NOT a valid triangle." << endl;
    }

    return 0;
}