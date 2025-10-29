#include <iostream>
using namespace std;


void tukar(int &a, int &b) {
    int sementara = a;
    a = b;
    b = sementara;
}

int partisi(int data[], int awal, int akhir) {
    int pivot = data[akhir]; 
    int indeksKiri = awal - 1;

    for (int i = awal; i < akhir; i++) {
        if (data[i] < pivot) {
            indeksKiri++;
            tukar(data[indeksKiri], data[i]);
        }
    }

    tukar(data[indeksKiri + 1], data[akhir]);
    return indeksKiri + 1;
}

void quickSort(int data[], int awal, int akhir) {
    if (awal < akhir) {
        int indeksPivot = partisi(data, awal, akhir);
        quickSort(data, awal, indeksPivot - 1);  
        quickSort(data, indeksPivot + 1, akhir); 
    }
}

int main() {
    int jumlah;
    cin >> jumlah;

    int data[1000];
    for (int i = 0; i < jumlah; i++)
        cin >> data[i];

    quickSort(data, 0, jumlah - 1);
    for (int i = 0; i < jumlah; i++)
        cout << data[i] << " ";

    cout << endl;
    return 0;
}
