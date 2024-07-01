#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"

class Mahasiswa {
public:
    bool authenticate(const std::string& username, const std::string& password) {
        std::ifstream file("data/mahasiswa.txt");
        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password) {
                currentMahasiswa = tokens[0];
                return true;
            }
        }
        return false;
    }

    void pilihMataKuliah() {
        std::string mataKuliah;
        std::cout << "Pilih Mata Kuliah: ";
        std::cin >> mataKuliah;
        mataKuliahDipilih = mataKuliah;
        std::cout << "Mata kuliah " << mataKuliah << " dipilih.\n";
    }

    void lihatTugasDanAbsen() {
        std::ifstream tugasFile("data/tugas.txt");
        std::ifstream absenFile("data/absen.txt");
        std::string line;
        
        std::cout << "Tugas untuk Mata Kuliah: " << mataKuliahDipilih << "\n";
        while (getline(tugasFile, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == mataKuliahDipilih) {
                std::cout << "Judul: " << tokens[1] << ", Deskripsi: " << tokens[2] << ", Deadline: " << tokens[3] << "\n";
            }
        }
        
        std::cout << "Absen untuk Mata Kuliah: " << mataKuliahDipilih << "\n";
        while (getline(absenFile, line)) {
            std::vector<std::string> tokens = split(line, ',');
            if (tokens[0] == mataKuliahDipilih) {
                std::cout << "Tanggal: " << tokens[1] << "\n";
            }
        }
    }

    void kumpulkanTugas() {
        std::ofstream file("data/kumpul_tugas.txt", std::ios::app);
        std::string tugasId, fileName;
        std::cout << "Masukkan ID Tugas: ";
        std::cin >> tugasId;
        std::cout << "Nama File: ";
        std::cin >> fileName;
       file << currentMahasiswa << "," << tugasId << "," << fileName << "\n";
        std::cout << "Tugas berhasil dikumpulkan.\n";
    }

    void absen() {
        std::ofstream file("data/absensi.txt", std::ios::app);
        std::string absenId;
        std::cout << "Masukkan ID Absen: ";
        std::cin >> absenId;
        file << currentMahasiswa << "," << absenId << "\n";
        std::cout << "Absen berhasil dilakukan.\n";
    }

private:
    std::string currentMahasiswa;
    std::string mataKuliahDipilih;
};

#endif