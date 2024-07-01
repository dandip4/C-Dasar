#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string nama;
    string npm;
    vector<string> matakuliah;
    vector<pair<string, time_t>> tugas; // Pair of task and submission time
    vector<pair<string, time_t>> absen; // Pair of attendance and attendance time
};

// Struktur Dosen
struct Dosen {
    string nama;
    string nidn;
    vector<string> matakuliah;
    vector<pair<string, time_t>> tugas; // Pair of task and deadline
    vector<pair<string, time_t>> absen; // Pair of attendance and deadline
};

// Struktur Admin
struct Admin {
    string username;
    string password;
};

// Linked list node untuk mahasiswa
struct MahasiswaNode {
    Mahasiswa mahasiswa;
    MahasiswaNode* next;
};

// Linked list node untuk dosen
struct DosenNode {
    Dosen dosen;
    DosenNode* next;
};

// Fungsi-fungsi
void addMahasiswa(MahasiswaNode*& head, Mahasiswa m) {
    MahasiswaNode* newNode = new MahasiswaNode{m, nullptr};
    if (!head) {
        head = newNode;
    } else {
        MahasiswaNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addDosen(DosenNode*& head, Dosen d) {
    DosenNode* newNode = new DosenNode{d, nullptr};
    if (!head) {
        head = newNode;
    } else {
        DosenNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printMahasiswa(MahasiswaNode* head) {
    while (head) {
        cout << "Nama: " << head->mahasiswa.nama << ", NPM: " << head->mahasiswa.npm << endl;
        head = head->next;
    }
}

void printDosen(DosenNode* head) {
    while (head) {
        cout << "Nama: " << head->dosen.nama << ", NIDN: " << head->dosen.nidn << endl;
        head = head->next;
    }
}

void tambahTugasDosen(DosenNode* dosenHead, string nidn, string tugas, time_t deadline) {
    while (dosenHead) {
        if (dosenHead->dosen.nidn == nidn) {
            dosenHead->dosen.tugas.push_back({tugas, deadline});
            break;
        }
        dosenHead = dosenHead->next;
    }
}

void tambahAbsenDosen(DosenNode* dosenHead, string nidn, string absen, time_t deadline) {
    while (dosenHead) {
        if (dosenHead->dosen.nidn == nidn) {
            dosenHead->dosen.absen.push_back({absen, deadline});
            break;
        }
        dosenHead = dosenHead->next;
    }
}

void daftarTugasMahasiswa(MahasiswaNode* mhsHead, string npm) {
    while (mhsHead) {
        if (mhsHead->mahasiswa.npm == npm) {
            cout << "Tugas Mahasiswa " << mhsHead->mahasiswa.nama << ":" << endl;
            for (const auto& tugas : mhsHead->mahasiswa.tugas) {
                cout << "Tugas: " << tugas.first << ", Waktu Pengumpulan: " << ctime(&tugas.second);
            }
            break;
        }
        mhsHead = mhsHead->next;
    }
}

void daftarAbsenMahasiswa(MahasiswaNode* mhsHead, string npm) {
    while (mhsHead) {
        if (mhsHead->mahasiswa.npm == npm) {
            cout << "Absen Mahasiswa " << mhsHead->mahasiswa.nama << ":" << endl;
            for (const auto& absen : mhsHead->mahasiswa.absen) {
                cout << "Absen: " << absen.first << ", Waktu: " << ctime(&absen.second);
            }
            break;
        }
        mhsHead = mhsHead->next;
    }
}

// Fungsi utama
int main() {
    Admin admin = {"admin", "admin"};
    MahasiswaNode* mahasiswaHead = nullptr;
    DosenNode* dosenHead = nullptr;

    Mahasiswa m1 = {"Alice", "123"};
    Mahasiswa m2 = {"Bob", "456"};
    addMahasiswa(mahasiswaHead, m1);
    addMahasiswa(mahasiswaHead, m2);

    Dosen d1 = {"Dr. Smith", "001"};
    Dosen d2 = {"Dr. John", "002"};
    addDosen(dosenHead, d1);
    addDosen(dosenHead, d2);

    // Menambahkan tugas ke dosen
    time_t now = time(0);
    tambahTugasDosen(dosenHead, "001", "Tugas 1", now + 7 * 24 * 60 * 60); // deadline 1 minggu
    tambahAbsenDosen(dosenHead, "002", "Absen 1", now + 3 * 24 * 60 * 60); // deadline 3 hari

    // Menampilkan daftar mahasiswa dan dosen
    printMahasiswa(mahasiswaHead);
    printDosen(dosenHead);

    // Daftar tugas dan absen mahasiswa
    daftarTugasMahasiswa(mahasiswaHead, "123");
    daftarAbsenMahasiswa(mahasiswaHead, "456");

    return 0;
}
    