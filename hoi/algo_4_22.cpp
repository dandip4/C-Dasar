#include<iostream>
using namespace std;

int main(){
    double celsius;

    cout << "Masukan Suhu Celcius: ";
    cin >> celsius;

    double kelvin = celsius + 273;
    double reamur = celsius * 4/5;
    double fahrenheit = celsius * 9/5+32;

    cout << "kelvin       : " << kelvin << endl;
    cout << "Reamur       : " << reamur << endl;
    cout << "Fahrenheit   : " << fahrenheit << endl;

}