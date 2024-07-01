#include <iostream>
using namespace std;

const int baris = 2;
const int kolom = 2;

void inputMatriks(double matriks[baris][kolom], const string &nama) {
    cout << "Masukkan nilai untuk matriks " << nama << " (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i)
        for (int j = 0; j < kolom; ++j)
            cin >> matriks[i][j];
}

void tampilkanMatriks(double matriks[baris][kolom], const string &nama) {
    cout << "Hasil " << nama << ":\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j)
            cout << matriks[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    double matriksA[baris][kolom],
    matriksB[baris][kolom], 
    hasilPenjumlahan[baris][kolom],
    hasilPengurangan[baris][kolom],
    hasilPerkalian[baris][kolom],
    hasilPembagian[baris][kolom];

    inputMatriks(matriksA, "A");
    inputMatriks(matriksB, "B");

    for (int i = 0; i < baris; ++i)
        for (int j = 0; j < kolom; ++j) {
            hasilPenjumlahan[i][j] = matriksA[i][j] + matriksB[i][j];
            hasilPengurangan[i][j] = matriksA[i][j] - matriksB[i][j];
            hasilPerkalian[i][j] = matriksA[i][j] * matriksB[i][j];
            hasilPembagian[i][j] = matriksA[i][j] / matriksB[i][j];
        }

    tampilkanMatriks(matriksA, "matriks A");
    tampilkanMatriks(matriksB, "matriks B");
    tampilkanMatriks(hasilPenjumlahan, "Penjumlahan");
    tampilkanMatriks(hasilPengurangan, "Pengurangan");
    tampilkanMatriks(hasilPerkalian, "Perkalian");
    tampilkanMatriks(hasilPembagian, "Pembagian");

    return 0;
}
