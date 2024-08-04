#include <iostream>

using namespace std;

int main() {
    int var = 10;        // Sebuah variabel integer
    int* ptr = &var;     // Sebuah pointer yang menyimpan alamat var

    cout << "Nilai var: " << var << endl;         // Menampilkan nilai var
    cout << "Alamat var: " << &var << endl;       // Menampilkan alamat var
    cout << "Nilai ptr: " << ptr << endl;         // Menampilkan nilai ptr (alamat var)
    cout << "Nilai yang ditunjuk ptr: " << *ptr << endl;  // Menampilkan nilai yang ditunjuk oleh ptr (nilai var)


    int &var1 = var;

    cout << var1;
    return 0;
}
