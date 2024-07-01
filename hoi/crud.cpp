#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Data {
    int id;
    string nama;
};

vector<Data> database;

void tambahData() {
    Data newData;
    cout << "Masukkan ID: ";
    cin >> newData.id;
    cin.ignore(); 
    cout << "Masukkan Nama: ";
    getline(cin, newData.nama);
    database.push_back(newData);
    cout << "Data telah ditambahkan." << endl;
}
 
void tampilkanData() {
    cout << "Data saat ini:" << endl;
    for (const Data& data : database) {
        cout << "ID: " << data.id << ", Nama: " << data.nama << endl;
    }
}

void perbaruiData() {
    int idToUpdate;
    cout << "Masukkan ID data yang akan diperbarui: ";
    cin >> idToUpdate;
    for (Data& data : database) {
        if (data.id == idToUpdate) {
            cin.ignore(); 
            cout << "Masukkan Nama baru: ";
            getline(cin, data.nama);
            cout << "Data telah diperbarui." << endl;
            return;
        }
    }
    cout << "Data dengan ID " << idToUpdate << " tidak ditemukan." << endl;
}

void hapusData() {
    int idToDelete;
    cout << "Masukkan ID data yang akan dihapus: ";
    cin >> idToDelete;
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->id == idToDelete) {
            it = database.erase(it);
            cout << "Data telah dihapus." << endl;
            return;
        }
    }
    cout << "Data dengan ID " << idToDelete << " tidak ditemukan." << endl;
}

int main() {
    while (true) {
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Perbarui Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih tindakan: ";
        
        int pilihan;
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                perbaruiData();
                break;
            case 4:
                hapusData();
                break;
            case 5:
                return 0; 
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
