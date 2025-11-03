#include <iostream>
using namespace std;

void balikArray (int *ptr, int n) {
    int *awal = ptr;
    int *akhir = ptr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main () {
    int n;
    cin >> n;

    int data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    balikArray(data, n);

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}