#include <iostream>
using namespace std;

void tukar(float &a, float &b) {
    float sementara = a;
    a = b;
    b = sementara;
}

void insertionSort(float data[], int jumlah) {
    for (int i = 1; i < jumlah; i++) {
        float kunci = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > kunci) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = kunci;
    }
}

void bucketSort(float data[], int jumlah) {
    const int banyakBucket = 10;
    float bucket[banyakBucket][1000];
    int jumlahDalamBucket[banyakBucket] = {0};

    for (int i = 0; i < jumlah; i++) {
        int indeks = data[i] * banyakBucket; 
        bucket[indeks][jumlahDalamBucket[indeks]] = data[i];
        jumlahDalamBucket[indeks]++;
    }

    for (int i = 0; i < banyakBucket; i++) {
        if (jumlahDalamBucket[i] > 0)
            insertionSort(bucket[i], jumlahDalamBucket[i]);
    }

    int indeks = 0;
    for (int i = 0; i < banyakBucket; i++) {
        for (int j = 0; j < jumlahDalamBucket[i]; j++) {
            data[indeks++] = bucket[i][j];
        }
    }
}

int main() {
    int jumlah;
    cin >> jumlah;

    float data[1000];
    for (int i = 0; i < jumlah; i++)
        cin >> data[i];

    bucketSort(data, jumlah);
    for (int i = 0; i < jumlah; i++)
        cout << data[i] << " ";

    cout << endl;
    return 0;
}
