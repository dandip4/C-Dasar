#include <iostream>
using namespace std;

double konversiSuhu(double suhu, char dari, char ke) {
    if (dari == ke) {
        return suhu;
    }

    if (dari == 'C') {
        if (ke == 'F') return (suhu * 9/5) + 32;
        if (ke == 'K') return suhu + 273;
        if (ke == 'R') return suhu * 0.8;
    } else if (dari == 'F') {
        if (ke == 'C') return (suhu - 32) * 5/9;
        if (ke == 'K') return (suhu - 32) * 5/9 + 273;
        if (ke == 'R') return (suhu - 32) * 4/9;
    } else if (dari == 'K') {
        if (ke == 'C') return suhu - 273;
        if (ke == 'F') return (suhu - 273) * 9/5 + 32;
        if (ke == 'R') return (suhu - 273) * 4/5;
    } else if (dari == 'R') {
        if (ke == 'C') return suhu * 1.25;
        if (ke == 'F') return (suhu * 9/4) + 32;
        if (ke == 'K') return (suhu * 5/4) + 273;
    }

    return suhu;
}

int main() {
    cout << "Konversi Suhu" << endl;

    double suhu;
    char dari, ke;

    cout << "Masukkan suhu: ";
    cin >> suhu;
    cout << "Dari satuan (C/F/K/R): ";
    cin >> dari;
    cout << "Ke satuan (C/F/K/R): ";
    cin >> ke;

    double hasil = konversiSuhu(suhu, dari, ke);
    cout << suhu << ' ' << dari << " sama dengan " << hasil << ' ' << ke << endl;

    return 0;
}
