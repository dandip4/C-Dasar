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