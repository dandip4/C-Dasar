#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string rumus;
    double a, t, p, l, r, luas, keliling;
    char lanjut;

    while (true) {
        cout << "Menghitung Luas dan Keliling \n";
        cout << "Masukan pilihan segitiga/persegi_panjang/lingkaran: ";
        cin >> rumus;

        if (rumus == "segitiga") {
            cout << "Masukan alas dan tinggi: ";
            cin >> a >> t;
            luas = 0.5 * a * t;
            keliling = 3 * a;
        } else if (rumus == "persegi_panjang") {
            cout << "Masukan panjang dan lebar: ";
            cin >> p >> l;
            luas = p * l;
            keliling = 2 * (p + l);
        } else if (rumus == "lingkaran") {
            cout << "Masukan jari-jari: ";
            cin >> r;
            luas = 3.14 * r * r;
            keliling = 2 * 3.14 * r;
        } else {
            cout << "Pilihan tidak ada" << endl;
            continue; 
        }

        cout << "Luas     : " << luas << endl;
        cout << "Keliling : " << keliling << endl;

        cout << "Apakah Anda ingin menghitung lagi? (y/n): ";
        cin >> lanjut;

        if (lanjut != 'y' && lanjut != 'Y') {
            break; 
        }
    }

    return 0;
}
