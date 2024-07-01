#include <iostream>
#include <cmath>

// Definisi parameter yang diberikan
const double viskositas_kecap = 0.391;  // kg / (m * s)
const double densitas_bola = 1.2e3;      // kg/m^3
const double densitas_fluida = 3.874e3;  // kg/m^3
const double g = 9.8;                    // m/s^2

// Fungsi untuk menghitung jari-jari bola
double hitung_jari_jari(double v) {
    double result = 9 * viskositas_kecap * v / (2 * (densitas_bola - densitas_fluida) * g);
    
    // Memastikan nilai dalam akar kuadrat tidak negatif atau infinity
    if (result < 0 || std::isinf(result) || std::isnan(result)) {
        return -1;  // Nilai yang tidak valid, bisa diatasi sesuai kebutuhan
    }

    return sqrt(result);
}

int main() {
    // Mencetak header
    std::cout << "Kecepatan (m/s)\tJari-jari Bola (m)\n";

    // Menghitung dan mencetak nilai untuk beberapa kecepatan
    for (double v = 0.1; v <= 5; v += 0.1) {
        double r = hitung_jari_jari(v);
        if (r != -1) {
            std::cout << v << "\t\t" << r << "\n";
        } else {
            std::cout << v << "\t\t" << "Nilai tidak valid" << "\n";
        }
    }

    return 0;
}
