#include <iostream>
using namespace std;

int main() {
  string var1 = "Belajar C++ di Duniailkom";
  string* var2 = &var1;

    *var2 = "tidak";
  string val = *var2;

  cout << var1 << endl;
  cout << var2 << endl;
  cout << val << endl;

  return 0;
}