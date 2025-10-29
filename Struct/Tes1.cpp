#include <iostream>
using namespace std;

struct Manusia {
    string namaPertama;
    string namaTengah;
    string namaAkhir;
    float gaji;
    int umur;
    int tinggiBadan;
};

void display_data (const Manusia&);

int main () {
    Manusia p {"Salomo", "Reinhard", "Kenedy", 1500000, 18, 171};
    display_data(p);
}

void display_data (const Manusia& p) {
    cout << "Nama Pertama : " << p.namaPertama << endl;
    cout << "Nama Tengah : " << p.namaTengah << endl;
    cout << "Nama Akhir : " << p.namaAkhir << endl;
    cout << "Gaji : " << p.gaji << endl;
    cout << "Umur : " << p.umur << endl;
    cout << "Tinggi Badan : " << p.tinggiBadan << endl;
}