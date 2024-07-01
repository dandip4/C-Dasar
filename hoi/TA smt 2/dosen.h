#ifndef DOSEN_H
#define DOSEN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"
#include "tugas.h"
#include "absen.h"

class Dosen {
public:
    bool authenticate(const std::string& username, const std::string& password) {
        std::ifstream file("data/dosen.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password) {
                currentDosen = tokens[0];
                return true;
            }
        }
        return false;
    }

    void createTugas() {
        std::ofstream file("data/tugas.txt", std::ios::app);
        std::string mataKuliah, judul, deskripsi, deadline;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::cout << "Judul: ";
        std::cin >> judul;
        std::cout << "Deskripsi: ";
        std::cin.ignore();
        std::getline(std::cin, deskripsi);
        std::cout << "Deadline (YYYY-MM-DD): ";
        std::cin >> deadline;
        file << mataKuliah << "," << judul << "," << deskripsi << "," << deadline << "," << currentDosen << "\n";
        std::cout << "Tugas berhasil dibuat.\n";
    }

    void createAbsen() {
        std::ofstream file("data/absen.txt", std::ios::app);
        std::string mataKuliah, tanggal;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::cout << "Tanggal (YYYY-MM-DD): ";
        std::cin >> tanggal;
        file << mataKuliah << "," << tanggal << "," << currentDosen << "\n";
        std::cout << "Absen berhasil dibuat.\n";
    }

    void viewAbsensi() {
        std::string mataKuliah;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::ifstream file("data/absen.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[2] == currentDosen) {
                std::cout << "Tanggal: " << tokens[1] << "\n";
            }
        }
    }

    void viewTugas() {
        std::string mataKuliah;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::ifstream file("data/tugas.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[4] == currentDosen) {
                std::cout << "Judul: " << tokens[1] << ", Deskripsi: " << tokens[2] << ", Deadline: " << tokens[3] << "\n";
            }
        }
    }

private:
    std::string currentDosen;
};

#endif
