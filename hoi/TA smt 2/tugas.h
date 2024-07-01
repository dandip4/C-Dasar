#ifndef TUGAS_H
#define TUGAS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"

class Tugas {
public:
    void tambahTugas() {
        std::ofstream file("data/tugas.txt", std::ios::app);
        std::string mataKuliah, judul, deskripsi, deadline, dosen;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::cout << "Judul: ";
        std::cin >> judul;
        std::cout << "Deskripsi: ";
        std::cin.ignore();
        std::getline(std::cin, deskripsi);
        std::cout << "Deadline (YYYY-MM-DD): ";
        std::cin >> deadline;
        std::cout << "Dosen: ";
        std::cin >> dosen;
        file << mataKuliah << "," << judul << "," << deskripsi << "," << deadline << "," << dosen << "\n";
        std::cout << "Tugas berhasil ditambahkan.\n";
    }
};

#endif
