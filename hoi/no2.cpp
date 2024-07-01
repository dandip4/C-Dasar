#include <iostream>

using namespace std;

const int BARIS_A = 2;
const int KOLOM_A = 3;
const int BARIS_B = 3;
const int KOLOM_B = 1;
const int BARIS_C = 2;
const int KOLOM_C = 1;

void inputMatrixA(int matrix[][KOLOM_A], const int baris, const int kolom) {
    cout << "Masukkan matriks A (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void inputMatrixB(int matrix[][KOLOM_B], const int baris, const int kolom) {
    cout << "Masukkan matriks B (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void inputMatrixC(int matrix[][KOLOM_C], const int baris, const int kolom) {
    cout << "Masukkan matriks C (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << "C[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrixA(const int matrix[][KOLOM_A], const int baris, const int kolom) {
    cout << "Matriks A (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void displayMatrixB(const int matrix[][KOLOM_B], const int baris, const int kolom) {
    cout << "Matriks B (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void displayMatrixC(const int matrix[][KOLOM_C], const int baris, const int kolom) {
    cout << "Matriks C (" << baris << "x" << kolom << "):\n";
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matrixA[BARIS_A][KOLOM_A];
    int matrixB[BARIS_B][KOLOM_B];
    int matrixC[BARIS_C][KOLOM_C];

    inputMatrixA(matrixA, BARIS_A, KOLOM_A);

    inputMatrixB(matrixB, BARIS_B, KOLOM_B);

    inputMatrixC(matrixC, BARIS_C, KOLOM_C);

    displayMatrixA(matrixA, BARIS_A, KOLOM_A);
    displayMatrixB(matrixB, BARIS_B, KOLOM_B);
    displayMatrixC(matrixC, BARIS_C, KOLOM_C);

    return 0;
}
