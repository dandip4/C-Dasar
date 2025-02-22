#ifndef AKADEMIK_H
#define AKADEMIK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility> 
#include <ctime> 
#include "utils.h"

using namespace std;

    string currentMahasiswa;
    string mataKuliah;
    string namaDosen;
    string minggu;

    string getCurrentDate() {
        time_t t = time(0);
        struct tm* now = localtime(&t);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
        return string(buffer);
    }

    bool isAfterDeadlineabsen(const string& currentDate) {
            ifstream file("data/absen.txt");
            string line;
            while (getline(file, line)) {
                vector<string> tokens = split(line, ',');
                if (tokens[0] == mataKuliah && tokens[1] == minggu) {
                    string deadline = tokens[2];
                    if (currentDate > deadline) {
                        return true;
                    }
                }
            }
            return false;
    }
    bool isAfterDeadlinetugas(const string& currentDate) {
            ifstream file("data/tugas.txt");
            string line;
            while (getline(file, line)) {
                vector<string> tokens = split(line, ',');
                if (tokens[0] == mataKuliah && tokens[1] == minggu) {
                    string deadline = tokens[4];
                    if (currentDate > deadline) {
                        return true;
                    }
                }
            }
            return false;
    }
    bool sudahAbsen() {
        string fileName = "data/absensi" + mataKuliah + ".txt";
        ifstream file(fileName);
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == minggu && tokens[1] == currentMahasiswa) {
                return false;
            }
        }
        return false;
    }
    bool sudahTugas() {
        string fileName = "data/kumpul_tugas_" + mataKuliah + ".txt";
        ifstream file(fileName);
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == minggu && tokens[1] == currentMahasiswa) {
                return true;
            }
        }
        return false;
    }
    void lihatTugasDanAbsen()
    {
        if (minggu.empty())
        {
            cout << "Minggu belum dipilih.\n";
            return;
        }

        ifstream tugasFile("data/tugas.txt");
        ifstream absenFile("data/absen.txt");
        string line;

        cout << "Tugas untuk minggu " << minggu << ":\n";
        while (getline(tugasFile, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[1] == minggu)
            {
                cout << "Judul: " << tokens[2] << ", Deskripsi: " << tokens[3] << ", Deadline: " << tokens[4] << "\n";
            }
        }

        cout << "Absen untuk minggu " << minggu << ":\n";
        while (getline(absenFile, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[1] == minggu)
            {
                cout << "Tanggal: " << tokens[2] << "\n";
            }
        }
    }

    void lihatMateri() {
        if (minggu.empty())
        {
            cout << "Minggu belum dipilih.\n";
            return;
        }

        ifstream file("data/materi_" + mataKuliah + ".txt");
        string line;
        cout << "Materi untuk mata kuliah " << mataKuliah << ":\n";
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if(tokens[0] == minggu)
            cout << line << endl;
        }
    }
    void absen()
    {
        if (minggu.empty())
        {
            cout << "Minggu belum dipilih.\n";
            return;
        }
        if (sudahAbsen()) {
        cout << "Anda sudah absen minggu ini.\n";
        return;
    }
        string currentDate = getCurrentDate();
            if (isAfterDeadlineabsen(currentDate)) {
                cout << "Tidak bisa absen setelah deadline.\n";
                return;
            }
        string status;
    cout << "Pilih status (hadir, sakit, izin, tanpa keterangan): ";
    cin >> status;
        string fileName = "data/absensi" + mataKuliah + ".txt";
        ofstream file(fileName, ios::app);
        file << minggu << "," << currentMahasiswa << "," << status  << "\n";
        cout << "Absen berhasil.\n";
    }

    
    void kumpulTugas()
    {
        if (minggu.empty())
        {
            cout << "Minggu belum dipilih.\n";
            return;
        }
        if (sudahTugas()) {
        cout << "Anda sudah Mengumpulkan Tugas minggu ini.\n";
        return;
    }
         string currentDate = getCurrentDate();
          if (isAfterDeadlinetugas(currentDate)) {
          cout << "Tidak bisa mengumpulkan tugas setelah deadline.\n";
        return;
    }
        string filePath;
        cout << "Path file tugas: ";
        cin >> filePath;
        
        string fileName = "data/kumpul_tugas_" + mataKuliah + ".txt";
        
        ofstream file(fileName, ios::app);
        file << minggu << "," << currentMahasiswa << "," << filePath << "\n";
        cout << "Tugas berhasil dikumpulkan di " << fileName << ".\n";
    }

#endif