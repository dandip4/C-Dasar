#include <iostream>
using namespace std;

int main() {
    double bilangan;

    // Meminta pengguna untuk memasukkan bilangan
    cout << "Masukkan sebuah bilangan: ";
    cin >> bilangan;

    // Menentukan apakah bilangan tersebut positif, negatif, atau nol
    if (bilangan > 0) {
        cout << "Bilangan ini adalah positif." << endl;
    } else if (bilangan < 0) {
        cout << "Bilangan ini adalah negatif." << endl;
    } else {
        cout << "Bilangan ini adalah nol." << endl;
    }

    return 0;
}