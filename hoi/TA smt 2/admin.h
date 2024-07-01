#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"
#include "mahasiswa.h"
#include "dosen.h"

using namespace std;

class Admin {
public:
    bool authenticate(const string& username, const string& password) {
        ifstream file("data/admin.txt");
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password) {
                return true;
            }
        }
        return false;
    }

    void crudMahasiswa() {
        int choice;
        while (true) {
            cout << "1. Tambah Mahasiswa\n2. Lihat Mahasiswa\n3. Update Mahasiswa\n4. Hapus Mahasiswa\n5. Kembali\n";
            cout << "Choose an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    tambahMahasiswa();
                    break;
                case 2:
                    lihatMahasiswa();
                    break;
                case 3:
                    updateMahasiswa();
                    break;
                case 4:
                    hapusMahasiswa();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        }
    }

    void crudDosen() {
        int choice;
        while (true) {
            cout << "1. Tambah Dosen\n2. Lihat Dosen\n3. Update Dosen\n4. Hapus Dosen\n5. Kembali\n";
            cout << "Choose an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    tambahDosen();
                    break;
                case 2:
                    lihatDosen();
                    break;
                case 3:
                    updateDosen();
                    break;
                case 4:
                    hapusDosen();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        }
    }

private:
    void tambahMahasiswa() {
        ofstream file("data/mahasiswa.txt", ios::app);
        string nama, npm;
        cout << "Nama: ";
        cin >> nama;
        cout << "NPM: ";
        cin >> npm;
        file << nama << "," << npm << "\n";
        std::cout << "Mahasiswa berhasil ditambahkan.\n";
    }

    void lihatMahasiswa() {
        std::ifstream file("data/mahasiswa.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            std::cout << "Nama: " << tokens[0] << ", NPM: " << tokens[1] << "\n";
        }
    }

    void updateMahasiswa() {
        std::string nama, npm;
        std::cout << "Masukkan NPM Mahasiswa yang ingin diupdate: ";
        std::cin >> npm;
        std::ifstream file("data/mahasiswa.txt");
        std::ofstream temp("data/temp.txt");
        std::string line;
        bool found = false;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[1] == npm) {
                found = true;
                std::cout << "Nama Baru: ";
                std::cin >> nama;
                temp << nama << "," << npm << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/mahasiswa.txt");
        rename("data/temp.txt", "data/mahasiswa.txt");
        if (found) {
            std::cout << "Mahasiswa berhasil diupdate.\n";
        } else {
            std::cout << "Mahasiswa tidak ditemukan.\n";
        }
    }

    void hapusMahasiswa() {
        std::string npm;
        std::cout << "Masukkan NPM Mahasiswa yang ingin dihapus: ";
        std::cin >> npm;
        std::ifstream file("data/mahasiswa.txt");
        std::ofstream temp("data/temp.txt");
        std::string line;
        bool found = false;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[1] == npm) {
                found = true;
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/mahasiswa.txt");
        rename("data/temp.txt", "data/mahasiswa.txt");
        if (found) {
            std::cout << "Mahasiswa berhasil dihapus.\n";
        } else {
            std::cout << "Mahasiswa tidak ditemukan.\n";
        }
    }

    void tambahDosen() {
        std::ofstream file("data/dosen.txt", std::ios::app);
        std::string nama, nidn, mataKuliah;
        std::cout << "Nama: ";
        std::cin >> nama;
        std::cout << "NIDN: ";
        std::cin >> nidn;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        file << nama << "," << nidn << "," << mataKuliah << "\n";
        std::cout << "Dosen berhasil ditambahkan.\n";
    }

    void lihatDosen() {
        std::ifstream file("data/dosen.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            std::cout << "Nama: " << tokens[0] << ", NIDN: " << tokens[1] << ", Mata Kuliah: " << tokens[2] << "\n";
        }
    }

    void updateDosen() {
        std::string nama, nidn, mataKuliah;
        std::cout << "Masukkan NIDN Dosen yang ingin diupdate: ";
        std::cin >> nidn;
        std::ifstream file("data/dosen.txt");
        std::ofstream temp("data/temp.txt");
        std::string line;
        bool found = false;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[1] == nidn) {
                found = true;
                std::cout << "Nama Baru: ";
                std::cin >> nama;
                std::cout << "Mata Kuliah Baru: ";
                std::cin >> mataKuliah;
                temp << nama << "," << nidn << "," << mataKuliah << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/dosen.txt");
        rename("data/temp.txt", "data/dosen.txt");
        if (found) {
            std::cout << "Dosen berhasil diupdate.\n";
        } else {
            std::cout << "Dosen tidak ditemukan.\n";
        }
    }

    void hapusDosen() {
        std::string nidn;
        std::cout << "Masukkan NIDN Dosen yang ingin dihapus: ";
        std::cin >> nidn;
        std::ifstream file("data/dosen.txt");
        std::ofstream temp("data/temp.txt");
        std::string line;
        bool found = false;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[1] == nidn) {
                found = true;
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/dosen.txt");
        rename("data/temp.txt", "data/dosen.txt");
        if (found) {
            std::cout << "Dosen berhasil dihapus.\n";
        } else {
            std::cout << "Dosen tidak ditemukan.\n";
        }
    }
};

#endif
