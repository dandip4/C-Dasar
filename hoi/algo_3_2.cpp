#include<iostream>
using namespace std;

int main(){
    string nama, ttl, gender, prodi; int nohp; int npm; float tb; char kelas; bool mahasiswa;

     cout << "Masukan Nama            : ";
     getline(cin, nama);
     cout << "Masukan Tempat dan Tanggal Lahir dengan format(17 Agustus 2005, Bogor): ";
     getline(cin, ttl);
     cout << "Masukan Jenis Kelamin (Laki-laki/Perempuan) : ";
     getline (cin, gender); 
     cout << "Masukan tinggi badan(cm): ";
     cin >> tb; 
     cout << "Status Mahasiswa : (Masukan 1 untuk Mahasiswa Aktif, dan 0 untuk Mahasiswa Tidak aktif): ";
     cin >> mahasiswa; 
     cout << "Masukan NPM             : ";
     cin >> npm;
     cout << "Masukan Program Studi   : ";                          //Danadipa Nugraha 065123199 Kelas G
     cin >> prodi;
     cout << "Masukan Kelas           : ";
     cin >> kelas;
     cout << "Masukan Nomor HP        : ";
     cin >> nohp;
cout <<endl;
cout <<endl;
cout <<endl;
     cout << "BIODATA DIRI"<< endl
          << "Nama                     : "<< nama << endl
          << "Tempat dan Tanggal Lahir : "<< ttl << endl
          << "Jenis Kelamin            : "<< gender << endl
          << "Tinggi Badan             : "<< tb << endl
          << "Status Mahasiswa         : "<< (mahasiswa ? "Mahasiswa Aktif" : "Mahasiswa Tidak Aktif") << endl
          << "NPM                      : "<< npm<< endl
          << "Program Studi            : "<< prodi<< endl
          << "Kelas                    : "<< kelas << endl
          << "Nomor HP                 : "<< nohp<< endl;  


     return 0;


}