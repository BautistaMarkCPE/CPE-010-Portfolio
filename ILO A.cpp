#include<iostream>
using namespace std;

void displaySum(int a, int b);
bool isGreater( int A, int B);
bool logicalOperations(bool x, bool y);

int main() {
    int num1, num2;
    bool val1, val2;

    cout <<"Enter First Number:";
    cin >> num1;
    cout <<"Enter Second Number:";
    cin >> num2;

    displaySum(num1, num2);

    if (isGreater(num1, num2))
        cout << num1 << " is greater than " << num2 << endl;
    else 
        cout << num1 << " is not greater than " << num2 << endl;

    cout << "Enter first boolean value (0 or 1) :";
    cin >> val1;
    
    cout << "Enter second boolean value (0 or 1) :";
    cin >> val2;

    if (logicalOperations(val1, val2))
        cout << "Logical operations completed succesfully" << endl;
    
    
    return 0;
}

void displaySum(int a, int b) {
    cout << "\nSum = " << a + b << endl;

}

bool isGreater(int A, int B) {
    return (A > B);
}

bool logicalOperations(bool x, bool y) {
    cout << "\nLogical AND = " << (x && y) << endl;
    cout << "Logical OR = " << (x || y) << endl;
    cout << "Logical NOT of first value = " << (!x) << endl;
    cout << "Logical NOT of second value = " << (!y) << endl;

    return true;
}

