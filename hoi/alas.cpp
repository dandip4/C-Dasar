#include <iostream>
using namespace std;

void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void Hasil(int arr[], int n) {
    for (int i = 0; i < n; ++i) {   // exchange sort, hampi sama dengan bubbles sort. hanya saja ada elemen menjadi pusat untuk menajadi tempat pertukaran
        cout << arr[i] << " ";      // Danadipa Nugraha Kelas G 065123199    
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan: ";
    Hasil(arr, n);

    exchangeSort(arr, n);

    cout << "Array setelah diurutkan: ";
    Hasil(arr, n);

    return 0;
}
