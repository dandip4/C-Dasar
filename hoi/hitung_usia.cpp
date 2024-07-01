#include <chrono>
#include <iostream>

using namespace std;

void log (int result){
    cout << "tahun kelahiran anda adalah"<< result << endl;

}
 
int main() {
    int tahun_lahir{};
    auto tahun_sekarang = std::chrono::system_clock::now();
    
    // Anda bisa memformat tahun_sekarang sebelum mencetaknya
    auto waktu_sekarang = std::chrono::system_clock::to_time_t(tahun_sekarang);
    tm waktu_struct = *std::localtime(&waktu_sekarang);
    int tahun_sekarang_format = waktu_struct.tm_year + 1900;
    
    cout << "Tahun sekarang: " << tahun_sekarang_format << endl;
    
    cout << "Masukan tahun kelahiran anda:";
    cin >> tahun_lahir;
    
    int usia = tahun_sekarang_format - tahun_lahir;
    cout << "Usia anda: " << usia << endl;
    
    return 0;
}





