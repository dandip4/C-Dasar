#include <iostream>

using namespace std;

int main() {
    // Membuat array 2 dimensi dengan 4 baris dan 2 kolom
    int array[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    // Menampilkan isi array
    cout << "Isi array 2 dimensi:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl; // Baris baru setelah setiap baris array
    }
    cout << array[0][1]<< endl ;
        cout << "array[0][0] = " << array[0][0] << endl;
    cout << "array[0][1] = " << array[0][1] << endl;
    cout << "array[1][0] = " << array[1][0] << endl;
    cout << "array[1][1] = " << array[1][1] << endl;
    cout << "array[2][0] = " << array[2][0] << endl;
    cout << "array[2][1] = " << array[2][1] << endl;
    cout << "array[3][0] = " << array[3][0] << endl;
    cout << "array[3][1] = " << array[3][1] << endl;
    return 0;
}
