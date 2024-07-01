#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Pegawai;

class CatatanKehadiran {
public:
    Pegawai* pegawai;
    time_t waktuAbsen;  
    string jenisKehadiran;

    CatatanKehadiran(Pegawai* pegawai, time_t absensi, const string& jenis)
        : pegawai(pegawai), waktuAbsen(absensi), jenisKehadiran(jenis) {}
};
    
class Pegawai {
public:
    string username;
    string password;
    string nama;
    bool Role;
    bool sudahLogin;

    Pegawai(const string& uname, const string& pwd, const string& namaPegawai, bool admin )
        : username(uname), password(pwd), nama(namaPegawai), Role(admin), sudahLogin(false) {}

};

class SistemKehadiran {
private:
    vector<Pegawai> daftarPegawai;
    vector<CatatanKehadiran> catatanKehadiran;
    Pegawai* penggunaSaatIni;
    unordered_map<string, time_t> waktuKehadiranTerakhir;

public:
    SistemKehadiran() : penggunaSaatIni(nullptr) {
        daftarPegawai.emplace_back("admin", "123", "Admin", true);
    }

    void jalankan() {
        int pilihan;
        do {
            cout << "\nMenu:\n";
            cout << "1. login\n";
            cout << "0. Keluar\n";
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    login();
                    break;
                case 0:
                    cout << "Keluar dari program.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        } while (pilihan != 0);
    }

private:
    void login() {  
        string username, password;
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        auto it = find_if(daftarPegawai.begin(), daftarPegawai.end(),
            [&](const Pegawai& pegawai) { return pegawai.username == username && pegawai.password == password; });

        if (it != daftarPegawai.end()) {
            penggunaSaatIni = &(*it);
            penggunaSaatIni->sudahLogin = true;

            if (penggunaSaatIni->Role) {
                menuAdmin();
            } else {
                menuPegawai();
            }
        } else {
            cout << "Login gagal, user tidak ditemukan atau Username/password salah.\n";
        }
    }

    void keluar() {
        if (penggunaSaatIni != nullptr) {
            cout << "Logout berhasil. Sampai jumpa, " << penggunaSaatIni->nama << "!\n";
            penggunaSaatIni->sudahLogin = false;
            penggunaSaatIni = nullptr;
        } else {
            cout << "Anda belum login.\n";
        }
    }

    void menuPegawai() {
        int pilihan;
        do {
            cout << "\n Login berhasil. Selamat datang, "<< penggunaSaatIni->nama<<"\n";
            cout << "Absen Pegawai:\n";
            cout << "1. Hadir\n";
            cout << "2. Izin\n";
            cout << "3. Sakit\n";
            cout << "4. Bolos\n";
            cout << "5. Logout\n";
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tandaiKehadiran("Hadir");
                    break;
                case 2:
                    tandaiKehadiran("Izin");
                    break;
                case 3:
                    tandaiKehadiran("Sakit");
                    break;
                case 4:
                    tandaiKehadiran("Bolos");
                    break;
                case 5:
                    keluar();
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        } while (pilihan != 5);
    }

    void menuAdmin() {
        int pilihan;
        do {
            cout << "\nMenu Admin:\n";
            cout << "1. Tambah Pegawai\n";
            cout << "2. Edit Pegawai\n";
            cout << "3. Hapus Pegawai\n";
            cout << "4. Daftar Pegawai\n";
            cout << "5. Laporan Kehadiran\n";
            cout << "6. Logout\n";
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahPegawai();
                    break;
                case 2:
                    editPegawai();
                    break;
                case 3:
                    hapusPegawai();
                    break;
                case 4:
                    tampilkanDaftarPegawai();
                    break;
                case 5:
                    tampilkanLaporanKehadiran();
                    break;
                case 6:
                    keluar();
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        } while (pilihan != 6);
    }

    void tambahPegawai() {
        if (penggunaSaatIni->Role) {
            string username, password, nama;
            cout << "Masukkan username pegawai baru: ";
            cin >> username;
            cout << "Masukkan password pegawai baru: ";
            cin >> password;
            cout << "Masukkan nama pegawai baru: ";
            cin >> nama;

            daftarPegawai.emplace_back(username, password, nama, false);
            cout << "Pegawai baru berhasil ditambahkan.\n";
        } else {
            cout << "Anda tidak memiliki izin untuk menambah pegawai.\n";
        }
    }

    void editPegawai() {
        if (penggunaSaatIni->Role) {
            string username;
            cout << "Masukkan username pegawai yang akan diedit: ";
            cin >> username;

            auto it = find_if(daftarPegawai.begin(), daftarPegawai.end(),
                [&](const Pegawai& pegawai) { return pegawai.username == username; });

            if (it != daftarPegawai.end()) {
                cout << "Informasi Pegawai Sebelum Diedit:\n";
                cout << "Username: " << it->username << "\n";
                cout << "Nama: " << it->nama << "\n";
                cout << "Role: " << (it->Role ? "Admin" : "Pegawai") << "\n";

                string namaBaru, usernameBaru, passwordBaru;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan username baru: ";
                cin >> usernameBaru;
                cout << "Masukkan password baru: ";
                cin >> passwordBaru;
              
                it->nama = namaBaru;
                it->username = usernameBaru;
                it->password = passwordBaru;

                cout << "\nInformasi Pegawai Setelah Diedit:\n";
                cout << "Username: " << it->username << "\n"; 
                cout << "Nama: " << it->nama << "\n";
                cout << "Role: " << (it->Role ? "Admin" : "Pegawai") << "\n";

                cout << "Pegawai berhasil diedit.\n";
            } else {
                cout << "Pegawai dengan username " << username << " tidak ditemukan.\n";
            }
        } 
    }

    void hapusPegawai() {
        if (penggunaSaatIni->Role) {
            string username;
            cout << "Masukkan username pegawai yang akan dihapus: ";
            cin >> username;

            auto it = find_if(daftarPegawai.begin(), daftarPegawai.end(),
                [&](const Pegawai& pegawai) { return pegawai.username == username; });

            if (it != daftarPegawai.end()) {
                daftarPegawai.erase(it);
                cout << "Pegawai berhasil dihapus.\n";
            } else {
                cout << "Pegawai dengan username " << username << " tidak ditemukan.\n";
            }
        } 
    }

    void tampilkanDaftarPegawai() const {
        if (penggunaSaatIni->Role) {
            cout << "Daftar Pegawai:\n";
            for (const auto& pegawai : daftarPegawai) {
                cout << "- " << pegawai.nama << " (Role: " << (pegawai.Role ? "Admin" : "Pegawai") << ")\n";
            }
        } else {
            cout << "Anda tidak memiliki izin untuk melihat daftar pegawai.\n";
        }
    }

    void tandaiKehadiran(const string& jenisKehadiran) {
        if (!penggunaSaatIni->Role) {
            auto waktuKehadiranTerakhirIt = waktuKehadiranTerakhir.find(penggunaSaatIni->username);
            if (waktuKehadiranTerakhirIt == waktuKehadiranTerakhir.end() ||
                difftime(time(nullptr), waktuKehadiranTerakhirIt->second) >= 24 * 60 * 60) {
                cout << "Selamat Anda sudah absen, silahkan logout\n";
                catatanKehadiran.emplace_back(penggunaSaatIni, time(nullptr), jenisKehadiran);
                waktuKehadiranTerakhir[penggunaSaatIni->username] = time(nullptr);
            } else {
                cout << "Anda sudah melakukan kehadiran dalam 24 jam terakhir.\n";
            }
        } else {
            cout << "Anda tidak memiliki izin untuk kehadiran.\n";
        }
    }

    void tampilkanLaporanKehadiran() const {
        if (penggunaSaatIni->Role) {
            cout << "Laporan Kehadiran:\n";
            cout << setw(20) << "Nama Pegawai" << setw(25) << "Waktu Kehadiran" << setw(15) << "Keterangan\n";

            for (const auto& catatan : catatanKehadiran) {
                cout << setw(20) << catatan.pegawai->nama
                    << setw(25) << formatWaktu(catatan.waktuAbsen)  
                    << setw(15) << catatan.jenisKehadiran << "\n";
            }
        } else {
            cout << "Anda tidak memiliki izin untuk melihat laporan kehadiran.\n";
        }
    }

    string formatWaktu(time_t timestamp) const {
        tm* waktuLokal = localtime(&timestamp);
        char buffer[25];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", waktuLokal);
        return buffer;
    }
    
};

int main() {
    SistemKehadiran sistemKehadiran;
    sistemKehadiran.jalankan();

    return 0;
}
