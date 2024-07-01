import numpy as np
import matplotlib.pyplot as plt

# Parameter yang diberikan
viskositas_kecap = 0.391  # kg / (m * s)
densitas_bola = 1.2e3  # kg/m^3
densitas_fluida = 3.874e3  # kg/m^3
g = 9.8  # m/s^2

# Fungsi untuk menghitung jari-jari bola
def hitung_jari_jari(v):
    return np.sqrt(9 * viskositas_kecap * v / (2 * (densitas_bola - densitas_fluida) * g))

# Buat nilai v dari 0.1 hingga 5 m/s
v_values = np.linspace(0.1, 5, 100)

# Hitung jari-jari untuk setiap nilai v
r_values = [hitung_jari_jari(v) for v in v_values]

# Plot grafik
plt.plot(v_values, r_values)
plt.title('Hubungan Jari-jari Bola terhadap Kecepatan Bola Jatuh')
plt.xlabel('Kecepatan (m/s)')
plt.ylabel('Jari-jari Bola (m)')
plt.grid(True)
plt.show()
