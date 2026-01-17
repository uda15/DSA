#include <iostream>
using namespace std;

// UDFs
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}

int main() {
    int choice, a, b;

    while (true) {
        cout << "\nPress 1 for +";
        cout << "\nPress 2 for -";
        cout << "\nPress 3 for *";
        cout << "\nPress 4 for /";
        cout << "\nPress 5 for %";
        cout << "\nPress 0 for the exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nProgram exited successfully.";
            break;
        }

        cout << "Enter the first number: ";
        cin >> a;

        cout << "Enter the second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                cout << "Addition of " << a << " and " << b << " is " << add(a, b);
                break;

            case 2:
                cout << "Subtraction of " << a << " and " << b << " is " << sub(a, b);
                break;

            case 3:
                cout << "Multiplication of " << a << " and " << b << " is " << mul(a, b);
                break;

            case 4:
                if (b != 0)
                    cout << "Division of " << a << " and " << b << " is " << divi(a, b);
                else
                    cout << "Division by zero is not allowed";
                break;

            case 5:
                if (b != 0)
                    cout << "Modulus of " << a << " and " << b << " is " << mod(a, b);
                else
                    cout << "Modulus by zero is not allowed";
                break;

            default:
                cout << "Invalid choice!";
        }
    }

    return 0;
}
