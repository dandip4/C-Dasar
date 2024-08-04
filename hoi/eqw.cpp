#include <iostream>
using namespace std;

// Mendefinisikan struct
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

int main() {
    // Membuat variabel dari tipe struct
    Mahasiswa mhs1;
    Mahasiswa mhs2;

    mhs2.nama = "as";
    mhs2.umur = 202;
    mhs2.ipk = 3.725;

    // Mencetak data anggota struct
    cout << "Nama: " << mhs2.nama << endl;
    cout << "Umur: " << mhs2.umur << endl;
    cout << "IPK: " << mhs2.ipk << endl;

    // Mengisi data anggota struct
    mhs1.nama = "Dani";
    mhs1.umur = 20;
    mhs1.ipk = 3.75;

    // Mencetak data anggota struct
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Umur: " << mhs1.umur << endl;
    cout << "IPK: " << mhs1.ipk << endl;

    return 0;
}
