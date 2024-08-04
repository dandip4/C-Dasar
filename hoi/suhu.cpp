#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {  
    cout << ">>> Menulis ke File" << endl;  
    ofstream file_keluaran;  
    file_keluaran.open("asa.txt");  

    cout << "sedang menulis..." << endl;  
    file_keluaran << "Haloo " << endl;  
    file_keluaran << "INI ADALAH SAYAaaaaaaaaaaa " << endl;  
    file_keluaran << "KRISNA" << endl;  
    file_keluaran << "KRISNA" << endl;  
    file_keluaran.close();  


    cout << "membaca dari file" << endl;
    string line;  
    ifstream file_input;  
    file_input.open("asa.txt");  

    cout << "membaca isi file latihan.txt" << endl;
    while (file_input) {  

        getline(file_input, line);
        cout << line << endl;  
    }  
    file_input.close();  
}  