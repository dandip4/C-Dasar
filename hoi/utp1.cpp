#include <iostream>
#include <vector>

using namespace std;

struct Pesanan {
    string nama;
    int usia;
    int jumlah_tiket;
    int nomor_pesanan;
};

int main() {
    vector<Pesanan> daftar;
    int nomor = 1;
    char opsi;

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

        daftar.push_back(pesanan);

        cout << "Pesanan berhasil disimpan. Nomor pesanan Anda: " << pesanan.nomor_pesanan << endl;

        cout << "Apakah Anda ingin memesan tiket lagi? (y/n): ";
        cin >> opsi;

    } while (opsi == 'y' || opsi == 'Y');

    cout << "\nDaftar Pesanan:\n";
    for (int i = 0; i < daftar.size(); i++) {
        cout << "Nomor Pesanan: " << daftar[i].nomor_pesanan << endl;
        cout << "Nama: " << daftar[i].nama << endl;
        cout << "Usia: " << daftar[i].usia << endl;
        cout << "Jumlah Tiket: " << daftar[i].jumlah_tiket << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}