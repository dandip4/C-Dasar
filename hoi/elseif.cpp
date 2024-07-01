#include <iostream>
using namespace std;

struct Pesanan {
    string nama;
    int usia;
    int jumlah_tiket;
    int nomor_pesanan;
};

int main() {
     int m = 100; 
    Pesanan daftar[m];
    int nomor = 1;
    char opsi;
    int jumlah_pesanan = 0; 

    do {
        Pesanan pesanan;

        cout << "Masukkan nama: ";
        cin >> pesanan.nama;

        cout << "Masukkan usia: ";
        cin >> pesanan.usia;

        cout << "Masukkan jumlah tiket: ";
        cin >> pesanan.jumlah_tiket;

        pesanan.nomor_pesanan = nomor;
        nomor++;

        daftar[jumlah_pesanan] = pesanan; 
        jumlah_pesanan++;

        cout << "Pesanan berhasil disimpan. Nomor pesanan Anda: " << pesanan.nomor_pesanan << endl;

        cout << "Apakah Anda ingin memesan lagi? (y/n): ";
        cin >> opsi;

    } while (opsi == 'y' || opsi == 'Y');

    cout << "Daftar Pesanan:";
    for (int i = 0; i < jumlah_pesanan; i++) {
        cout << "Nomor Pesanan: " << daftar[i].nomor_pesanan << endl;
        cout << "Nama: " << daftar[i].nama << endl;
        cout << "Usia: " << daftar[i].usia << endl;
        cout << "Jumlah Tiket: " << daftar[i].jumlah_tiket << endl;
    }

    return 0;
}
