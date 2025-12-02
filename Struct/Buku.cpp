#include <iostream>
using namespace std;

struct Buku {
    char judul[50];
    char penulis[50];
    int tahun;
};

int panjang(const char s[]) {
    int i=0; while(s[i] != '\0') i++; 
    return i;
}

char toLower(char c){
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

bool samaIgnoreCase(const char a[], const char b[]) {
    int pa = panjang(a), pb = panjang(b);
    if (pa != pb) return false;

    for (int i = 0; i < pa; i++) {
        if (toLower(a[i]) != toLower(b[i])) return false;
    }
    return true;
}

int main() {
    Buku db[100];
    int n = 0;

    int menu;
    char key[50];

    do {
        cout << "\n1. Tambah\n2. Cari\n3. Tampilkan\n0. Keluar\nPilih: ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            cout << "Judul: ";
            cin.getline(db[n].judul, 50);

            cout << "Penulis: ";
            cin.getline(db[n].penulis, 50);

            cout << "Tahun: ";
            cin >> db[n].tahun;
            cin.ignore();

            n++;
        }
        else if (menu == 2) {
            cout << "Cari judul: ";
            cin.getline(key, 50);

            bool ketemu = false;
            for (int i = 0; i < n; i++) {
                if (samaIgnoreCase(db[i].judul, key)) {
                    cout << "Ditemukan!\n";
                    cout << db[i].judul << " - " << db[i].penulis << " - " << db[i].tahun << endl;
                    ketemu = true;
                }
            }
            if (!ketemu) cout << "Tidak ada.\n";
        }
        else if (menu == 3) {
            for (int i = 0; i < n; i++) {
                cout << i+1 << ". " << db[i].judul << " - " << db[i].penulis 
                     << " - " << db[i].tahun << endl;
            }
        }

    } while (menu != 0);
}
