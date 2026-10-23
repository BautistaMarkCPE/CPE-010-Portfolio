#include<iostream>
#include<cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;

    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;

    double distance = calculateDistance(x1, y1, x2, y2);
    cout << "The distance between the two points is: " << distance << endl;

    return 0;
}