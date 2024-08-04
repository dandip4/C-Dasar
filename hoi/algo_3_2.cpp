#include <iostream>
using namespace std;

int main() {
    const int n = 5; // Ukuran array
    int arr[n] = {64, 25, 12, 22, 11};

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        // Temukan elemen terkecil dari bagian yang belum diurutkan
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pertama dari bagian yang belum diurutkan
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Cetak array yang telah diurutkan
    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
