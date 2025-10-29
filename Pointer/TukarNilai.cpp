#include <iostream>
using namespace std;

void tukar (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a, b;
    cout << "Masukkan nilai A : ";
    cin >> a;
    cout << "Masukkan nilai B : ";
    cin >> b;

    cout << "\nSebelum Ditukar A = " << a << ", B = " << b << endl;
    tukar (&a, &b);
    cout << "\nSesudah Ditukar A = " << a << ", B = " << b << endl;

    return 0;
}