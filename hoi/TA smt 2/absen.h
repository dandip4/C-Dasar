#ifndef ABSEN_H
#define ABSEN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"

class Absen {
public:
    void tambahAbsen() {
        std::ofstream file("data/absen.txt", std::ios::app);
        std::string mataKuliah, tanggal, dosen;
        std::cout << "Mata Kuliah: ";
        std::cin >> mataKuliah;
        std::cout << "Tanggal (YYYY-MM-DD): ";
        std::cin >> tanggal;
        std::cout << "Dosen: ";
        std::cin >> dosen;
        file << mataKuliah << "," << tanggal << "," << dosen << "\n";
        std::cout << "Absen berhasil ditambahkan.\n";
    }
};

#endif
