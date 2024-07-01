#include <iostream>
using namespace std;

int main() {
    double a;

    while (true) {
        cout << "Masukkan angka (masukkan 0 untuk keluar): ";
        cin >> a;

        if (a > 0) {
            cout << "angka positif." << endl;
        } else if (a < 0) {
            cout << "angka negatif." << endl;
        } else if(a == 0) {
             cout << "angka nol." << endl;
            break; 
        } 
        
    }

    return 0;
}
