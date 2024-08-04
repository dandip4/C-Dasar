#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Membuat Stack
    stack<string> buah;

    // Menambahkan elemen ke dalam Stack
    buah.push("Apel");
    buah.push("Jeruk");
    buah.push("Mangga");

    cout << "Isi dari Stack kamu adalah: ";

    // Mencetak elemen elemen yang ada dalam Stack
    while (!buah.empty()) {
        cout << buah.top() << ", ";
        buah.pop();
    }

    return 0;
}