#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    Mahasiswa mhs = {"Salomo", 20};
    Mahasiswa *ptr = &mhs; 

    cout << "Nama: " << ptr->nama << endl;
    cout << "Umur: " << ptr->umur << endl;

    ptr->umur = 21; 

    cout << "Umur setelah diubah: " << mhs.umur << endl;
    return 0;
}
