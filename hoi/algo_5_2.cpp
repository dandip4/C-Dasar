#include <iostream>
using namespace std;

int main() {
    char h;

    while (true) {
        cout << "Masukkan sebuah huruf (tekan 'x' untuk keluar): ";
        cin >> h;

        if (h == 'x') {
            cout << "Keluar dari program." << endl;
            break; 
        }

        h = tolower(h);

        if (h >= 'a' && h <= 'z') {
            if (h == 'a' || h == 'e' || h == 'i' || h == 'o' || h == 'u') {
                cout << "Huruf vokal" << endl;
            } else {
                cout << "Huruf konsonan" << endl;
            }
            } else {
                cout << "Ini bukan huruf alfabet" << endl;
            }
    }

    return 0;
}
