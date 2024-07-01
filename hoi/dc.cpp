#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

class Murid {
public:
    string nama;
    string sekolah;
    string kelas;
    string waktu;

    Murid(const string& kelas, const string& nama, const string& sklh)
        : kelas(kelas), nama(nama), sekolah(sklh) {
            auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            waktu = ctime(&currentTime);
        }
};

class Guru {
public:
    string nama;
    string walikelas;
    string matapelajaran;
    string waktu;

    Guru(const string& nama, const string& walikelas, const string& matapelajaran)
        : nama(nama), walikelas(walikelas), matapelajaran(matapelajaran) {
            auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
            waktu = ctime(&currentTime);
        }
};

class Pemanggilan {
public:
    vector<Murid> daftarmurid;
    vector<Guru> daftarguru;

public:

    void murid() {
        string kelas, nama, sekolah;

        cout << "Masukan Nama Murid: ";
        cin >> nama;
        cout << "Masukan kelas Murid: ";
        cin >> kelas;
        cout << "Masukan sekolah Murid: ";
        cin >> sekolah;

        daftarmurid.emplace_back(nama, kelas, sekolah);
    }

    void guru() {
        string nama, walikelas, matapelajaran;

        cout << "Masukan Nama Guru: ";
        cin >> nama;
        cout << "Masukan Wali Kelas Guru: ";
        cin >> walikelas;
        cout << "Masukan Mata Pelajaran Guru: ";
        cin >> matapelajaran;

        daftarguru.emplace_back(nama, walikelas, matapelajaran);
    }

    void tampilkanMurid() {
        cout << "Daftar Murid:\n";
        cout <<  setw(20) << "Nama" << setw(20) << "Kelas" << setw(20) << "Sekolah" << setw(20) << "Waktu\n";
        for (const auto& murid : daftarmurid) {
            cout <<  setw(20) << murid.nama <<  setw(20) << murid.kelas <<  setw(20) << murid.sekolah << setw(20) << murid.waktu;
        }
    }

    void tampilkanGuru() {
        cout << "Daftar Guru:\n";
        cout <<  setw(20) << "Nama" << setw(20) << "Wali Kelas" << setw(20) << "Mata Pelajaran" << setw(20) << "Waktu\n";
        for (const auto& guru : daftarguru) {
            cout <<  setw(20) << guru.nama <<  setw(20) << guru.walikelas <<  setw(20) << guru.matapelajaran << setw(20) << guru.waktu;
        }
    }

    void tampilkanMenu() {
        int pilihan;

        do {
            cout << "Menu Utama:\n";
            cout << "1. Tambah Murid\n";
            cout << "2. Tambah Guru\n";
            cout << "3. Tampilkan Daftar Murid\n";
            cout << "4. Tampilkan Daftar Guru\n";
            cout << "5. Keluar\n";
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
            case 1:
                murid();
                break;
            case 2:
                guru();
                break;
            case 3:
                tampilkanMurid();
                break;
            case 4:
                tampilkanGuru();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
            }
        } while (pilihan != 5);
    }
};

int main() {
    Pemanggilan pemanggilanObj;
    pemanggilanObj.tampilkanMenu();

    return 0;
}
