#include <iostream>
using namespace std;

struct Mahasiswa {
    char nama[50];
    char NIM[20];
    int nilai[3];
};

double hitungRataRata(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main () {
    Mahasiswa m[5];

    for (int i = 0; i < 5; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama: ";

         cin.getline(m[i].nama, 50);

        cout << "NIM: ";
        cin.getline(m[i].NIM, 20);

        cout << "3 nilai: ";
        cin >> m[i].nilai[0] >> m[i].nilai[1] >> m[i].nilai[2];
        cin.ignore();
    }

    int idx = 0;
    double rataMax = hitungRataRata(m[0].nilai[0], m[0].nilai[1], m[0].nilai[2]);

    for (int i = 1; i < 5; i++) {
        double r = hitungRataRata(m[i].nilai[0], m[i].nilai[1], m[i].nilai[2]);
        if (r > rataMax) {
            rataMax = r;
            idx = i;
        }
    }

    cout << "\nMahasiswa dengan rata-rata tertinggi:\n";
    cout << m[idx].nama << " (" << m[idx].NIM << ") -> " << rataMax << endl;
}
