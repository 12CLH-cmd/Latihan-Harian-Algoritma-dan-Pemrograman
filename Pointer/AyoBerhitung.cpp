#include <iostream>
using namespace std;

void inputData(int *ptr, int n) {
    cout << "Masukkan " << n << " angka : ";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i); 
    }
}

void hitungStatistik(int *ptr, int n, int &maks, int &min, double &rata) {
    maks = *ptr; 
    min  = *ptr;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int nilai = *(ptr + i);

        if (nilai > maks) maks = nilai;
        if (nilai < min)  min  = nilai;

        total += nilai;
    }

    rata = static_cast<double>(total) / n;
}

int main() {
    int n;
    cout << "Masukkan jumlah data (maks 100) : ";
    cin >> n;
    int data[100];

    inputData(data, n);


    int maksimum, minimum;
    double rataRata;

    hitungStatistik(data, n, maksimum, minimum, rataRata);

    cout << "\nNilai maksimum = " << maksimum << endl;
    cout << "Nilai minimum  = " << minimum << endl;
    cout << "Rata-rata      = " << rataRata << endl;

    return 0;
}
