#include <iostream>
using namespace std;

// Function declarations for basic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is undefined." << endl;
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    int choice;

    // Displaying menu
    cout << "Select operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "Enter the number corresponding to the operation (1/2/3/4): ";
    cin >> choice;

    // Getting numbers from user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Performing the chosen operation
    double result;
    switch (choice) {
        case 1:
            result = add(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 2:
            result = subtract(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = multiply(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 4:
            result = divide(num1, num2);
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Invalid input. Please select a valid operation." << endl;
    }

    return 0;
}
