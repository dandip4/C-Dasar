#include <iostream>
using namespace std;

void DoubleNumber(int* ptr) {
    *ptr *= 2;
}

void ChangeNumber(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    ChangeNumber(&num1, &num2);  // Memanggil fungsi dengan alamat num1 dan num2
    cout << "Nilai num1 setelah pertukaran: " << num1 << endl;  // Output: 20
    cout << "Nilai num2 setelah pertukaran: " << num2 << endl; 
     int numa = 51;
    DoubleNumber(&numa);  // Memanggil fungsi dengan alamat num
    cout << "Nilai num setelah penggandaan: " << numa << endl;  // Output: 10 // Output: 10
    return 0;
}