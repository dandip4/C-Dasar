#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> lomba; 
    string nama;
    cout << "Masukkan nama-nama peserta:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Masukkan nama-nama peserta:" << i+1 << ": ";
        cin>>nama;
        lomba.push(nama);
    }

    string juara[3] = {"Juara 1: ", "Juara 2: ", "Juara 3: "};

    for (int i = 0; i < 3; ++i) {
        cout << juara[i] << lomba.front() << endl;
        lomba.pop();
    }

    return 0;
}
