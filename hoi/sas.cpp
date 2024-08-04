// #include <iostream>
// #include <conio.h>

// using namespace std;

// void garis(); // Deklarasi fungsi untuk membuat garis pemisah

// int main() {
//     int baris; // Variabel untuk menyimpan jumlah baris matriks

//     // Meminta pengguna memasukkan jumlah baris
//     cout << "Masukkan Banyak Matriks = ";
//     cin >> baris;

//     garis(); // Memanggil fungsi untuk membuat garis

//     // Membuat array dengan ukuran yang ditentukan oleh pengguna
//     int array[baris];

//     // Mengisi elemen-elemen array dengan nilai yang dimasukkan pengguna
//     for (int i = 0; i < baris; i++) {
//         cout << "Masukkan data Matriks ke-" << i+1 << " = ";
//         cin >> array[i];
//     }

//     garis(); // Memanggil fungsi untuk membuat garis

//     // Menampilkan elemen-elemen array yang telah diisi
//     cout << "Ini data array kamu" << endl;
//     for (int j = 0; j < baris; j++) {
//         cout << array[j] << " ";
//     }
//     cout << endl;

//     getch(); // Menunggu pengguna menekan tombol sebelum program selesai

//     return 0;
// }

// void garis() {
//     cout << "\n------------------------\n";
// }