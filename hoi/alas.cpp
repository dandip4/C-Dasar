#include <iostream>
using namespace std;

int main()
{
    const int n = 5; // Ukuran array

    int arr[n] = {64, 25, 12, 22, 11};

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Tukar arr[j] dan arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Cetak array yang telah diurutkan
    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
