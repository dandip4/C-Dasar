// #include <iostream>

// using namespace std;
// int main()
// {
//     cout << "Hello, World!";
// }

// #include <iostream>

// using namespace std;
// int main()
// {
//     int a, b, hasil;

//     cout << "masukan angka pertama: ";
//     cin >> a;
//     cout << endl;
//     cout << "masukan Angka kedua: ";
//     cin >> b;

//     hasil = a + b;

//     cout << "hasil penjumlahanya adalah " << hasil ;
// }

// #include <iostream>

// using namespace std;
// int main()
// {
//     int a, hasil ;

//     cout << "masukan angka yang akan diperikasa apakah ganjil atau genap: ";
//     cin >> a;
//     if (a % 2 == 0)
//     {
//         cout << "ini adalah bialnga genap";
//     } else{
//         cout << "ini adalah bilangan ganjil";
//     }
    
// }

// #include <iostream>

// using namespace std;
// int main()
// {
//     for (int i = 0; i <= 100; i++)
//     {
//         cout << i << endl;
//     }
    
// }

// #include <iostream>

// using namespace std;


// int add(int a, int b)
// {
//     int hasil = a + b;
//     return hasil;
// }
// int main()
// {
//     int b = add(3,1);
//     cout << b;
// }

#include <iostream>
using namespace std;

float data[] = {1.6, 1.9};
double angka[] = {1, 2, 3, 9, 7.9};
bool logic[] = {true, false};
int number[] = {1, 4, 5, 6, 7};
string nama[] = {"udin", "santoso", "joko", "nizwan"};
char huruf[] = {'a', 'b', 'c', 'd'}; // Asumsikan 'b', 'c', dan 'd' yang benar

string Display(string nama) {
    return nama;
}

double Desimal(double angka) {
    return angka;
}

int main() {
    string namaYangDitampilkan = Display(nama[1]);
    cout << "Menampilkan array dengan Fungsi: " << namaYangDitampilkan << endl;

    double angkaYangDitampilkan = Desimal(angka[4]);
    cout << "Menampilkan array dengan Fungsi: " << angkaYangDitampilkan << endl;

    return 0;
}