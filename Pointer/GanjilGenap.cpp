#include <iostream>
using namespace std;

void countEvenOdd (int *arr, int n, int *even, int *odd) {
    *even = 0;
    *odd = 0;

    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0)
            (*even)++;
        else 
            (*odd)++;
    }
}

int main () {
    int n;
    cout << "Masukkan jumlah elemen : ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array : ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int evenCount, oddCount;
    countEvenOdd (arr, n, &evenCount, &oddCount);

    cout << "Jumlah bilangan genap : " << evenCount << endl;
    cout << "Jumlah bilangan ganjil : " << oddCount << endl;

    return 0;

}