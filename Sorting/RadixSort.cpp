#include <iostream>
using namespace std;

int cariMaksimum(int data[], int jumlah) {
    int maksimum = data[0];
    for (int i = 1; i < jumlah; i++) {
        if (data[i] > maksimum)
            maksimum = data[i];
    }
    return maksimum;
}

void countingSort(int data[], int jumlah, int posisi) {
    int hasilSementara[1000];
    int hitung[10] = {0};

    for (int i = 0; i < jumlah; i++)
        hitung[(data[i] / posisi) % 10]++;

    for (int i = 1; i < 10; i++)
        hitung[i] += hitung[i - 1];

    for (int i = jumlah - 1; i >= 0; i--) {
        int digit = (data[i] / posisi) % 10;
        hasilSementara[hitung[digit] - 1] = data[i];
        hitung[digit]--;
    }

    for (int i = 0; i < jumlah; i++)
        data[i] = hasilSementara[i];
}

void radixSort(int data[], int jumlah) {
    int maksimum = cariMaksimum(data, jumlah);

    for (int posisi = 1; maksimum / posisi > 0; posisi *= 10)
        countingSort(data, jumlah, posisi);
}

int main() {
    int jumlah;
    cin >> jumlah;

    int data[1000];
    for (int i = 0; i < jumlah; i++)
        cin >> data[i];

    radixSort(data, jumlah);

    for (int i = 0; i < jumlah; i++)
        cout << data[i] << " ";

    cout << endl;
    return 0;
}
