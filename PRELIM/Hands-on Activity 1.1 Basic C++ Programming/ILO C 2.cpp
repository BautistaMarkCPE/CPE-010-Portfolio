#include<iostream>
using namespace std;

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    double kelvin;

    cout << "Enter Temperature in Kelvin: ";
    cin >> kelvin;

    double fahrenheit = kelvinToFahrenheit(kelvin);
    cout << kelvin << " Kelvin is equal to " << fahrenheit << " Fahrenheit." << endl;

    return 0;
}