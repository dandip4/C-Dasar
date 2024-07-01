#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "admin.h"
#include "dosen.h"
#include "mahasiswa.h"
#include "tugas.h"
#include "absen.h"
#include "utils.h"

void adminMenu();
void dosenMenu();
void mahasiswaMenu();

int main() {
    int choice;
    while (true) {
        std::cout << "1. Admin\n2. Dosen\n3. Mahasiswa\n4. Exit\n";
        std::cout << "Choose your role: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                dosenMenu();
                break;
            case 3:
                mahasiswaMenu();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}

void adminMenu() {
    Admin admin;
    std::string username, password;
    std::cout << "Admin Login\nUsername: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (!admin.authenticate(username, password)) {
        std::cout << "Login failed!\n";
        return;
    }

    int choice;
    while (true) {
        std::cout << "1. CRUD Mahasiswa\n2. CRUD Dosen\n3. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                admin.crudMahasiswa();
                break;
            case 2:
                admin.crudDosen();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}

void dosenMenu() {
    Dosen dosen;
    std::string username, password;
    std::cout << "Dosen Login\nNama: ";
    std::cin >> username;
    std::cout << "NIDN: ";
    std::cin >> password;

    if (!dosen.authenticate(username, password)) {
        std::cout << "Login failed!\n";
        return;
    }

    int choice;
    while (true) {
        std::cout << "1. Buat Tugas\n2. Buat Absen\n3. Lihat Daftar Absen\n4. Lihat Daftar Tugas\n5. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                dosen.createTugas();
                break;
            case 2:
                dosen.createAbsen();
                break;
            case 3:
                dosen.viewAbsensi();
                break;
            case 4:
                dosen.viewTugas();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}

void mahasiswaMenu() {
    Mahasiswa mahasiswa;
    std::string username, password;
    std::cout << "Mahasiswa Login\nNama: ";
    std::cin >> username;
    std::cout << "NPM: ";
    std::cin >> password;

    if (!mahasiswa.authenticate(username, password)) {
        std::cout << "Login failed!\n";
        return;
    }

    int choice;
    while (true) {
        std::cout << "1. Pilih Mata Kuliah\n2. Lihat Tugas dan Absen\n3. Kumpulkan Tugas\n4. Absen\n5. Logout\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                mahasiswa.pilihMataKuliah();
                break;
            case 2:
                mahasiswa.lihatTugasDanAbsen();
                break;
            case 3:
                mahasiswa.kumpulkanTugas();
                break;
            case 4:
                mahasiswa.absen();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}
