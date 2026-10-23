#include<iostream> 
using namespace std;

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;
     
    cout << "Enter first number:";
    cin >> num1;

    cout << "Enter second number:";
    cin >> num2;

    cout << "\nBefore swapping:\n";
    cout << "First Number = " << num1 << endl;
    cout << "Second Number = " << num2 << endl;

    swapNumbers(num1, num2);

    cout << "\nAfter swapping:\n";
    cout << "First Number = " << num1 << endl;
    cout << "Second Number = " << num2 << endl;

    return 0;
}