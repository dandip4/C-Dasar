#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;

    cout << "Masukkan dua angka: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;

        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            else
                cout << "Pembagian dengan nol tidak diperbolehkan";
            break;

        default:
            cout << "Error! Operator yang dimasukkan tidak valid";
            break;
    }

    return 0;
}
