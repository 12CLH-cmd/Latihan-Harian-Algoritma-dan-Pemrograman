#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int sementara = a;
    a = b;
    b = sementara;
}

void heapify(int data[], int ukuran, int akar) {
    int terbesar = akar;          
    int kiri = 2 * akar + 1;      
    int kanan = 2 * akar + 2;     

    if (kiri < ukuran && data[kiri] > data[terbesar])
        terbesar = kiri;

    if (kanan < ukuran && data[kanan] > data[terbesar])
        terbesar = kanan;

    if (terbesar != akar) {
        tukar(data[akar], data[terbesar]);
        heapify(data, ukuran, terbesar);
    }
}

void heapSort(int data[], int ukuran) {
    for (int i = ukuran / 2 - 1; i >= 0; i--)
        heapify(data, ukuran, i);
    for (int i = ukuran - 1; i > 0; i--) {
        tukar(data[0], data[i]);
        heapify(data, i, 0);
    }
}

int main() {
    int jumlah;
    cin >> jumlah;

    int data[1000];
    for (int i = 0; i < jumlah; i++)
        cin >> data[i];

    heapSort(data, jumlah);
    for (int i = 0; i < jumlah; i++)
        cout << data[i] << " ";

    cout << endl;
    return 0;
}
