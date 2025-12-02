#include <iostream>
using namespace std;

struct Produk {
    char nama[50];
    int harga;
    int stok;
};

int str_len(const char*s){int i=0; while(s[i]) i++; return i;}
void str_copy(char*d, const char*s){ int i=0; while((d[i]=s[i])) i++; }
bool str_equal(const char*a,const char*b){
    int i=0; while(a[i] && b[i]){ if(a[i]!=b[i]) return false; i++; } return a[i]==b[i];
}

int main(){
    Produk* arr = NULL;
    int size = 0;
    int cap = 0;
    int pilih;
    char tmp[100];

    auto ensure_capacity = [&](int need){
        if(cap >= need) return;
        int newcap = (cap==0) ? 4 : cap*2;
        while(newcap < need) newcap *= 2;
        Produk* t = new Produk[newcap];
        for(int i=0;i<size;i++) t[i]=arr[i];
        if(arr) delete [] arr;
        arr = t;
        cap = newcap;
    };

    do{
        cout<<"\n1.Tambah 2.Hapus(nama) 3.Update 4.Tampil 0.Keluar\nPilih: ";
        cin>>pilih; cin.ignore();
        if(pilih==1){
            ensure_capacity(size+1);
            cout<<"Nama: "; cin.getline(arr[size].nama,50);
            cout<<"Harga: "; cin>>arr[size].harga;
            cout<<"Stok: "; cin>>arr[size].stok; cin.ignore();
            size++;
            cout<<"Ditambahkan.\n";
        } else if(pilih==2){
            cout<<"Nama yang dihapus: "; cin.getline(tmp,100);
            int idx=-1;
            for(int i=0;i<size;i++) if(str_equal(arr[i].nama,tmp)){ idx=i; break; }
            if(idx==-1) cout<<"Tidak ditemukan.\n";
            else{
                for(int i=idx;i<size-1;i++) arr[i]=arr[i+1];
                size--;
                cout<<"Dihapus.\n";
            }
        } else if(pilih==3){
            cout<<"Nama yang diupdate: "; cin.getline(tmp,100);
            int idx=-1;
            for(int i=0;i<size;i++) if(str_equal(arr[i].nama,tmp)){ idx=i; break; }
            if(idx==-1) cout<<"Tidak ditemukan.\n";
            else{
                cout<<"Harga baru: "; cin>>arr[idx].harga;
                cout<<"Stok baru: "; cin>>arr[idx].stok; cin.ignore();
                cout<<"Diupdate.\n";
            }
        } else if(pilih==4){
            cout<<"Daftar Produk:\n";
            for(int i=0;i<size;i++){
                cout<<i+1<<". "<<arr[i].nama<<" | Harga: "<<arr[i].harga<<" | Stok: "<<arr[i].stok<<"\n";
            }
            if(size==0) cout<<"(kosong)\n";
        }
    } while(pilih!=0);

    if(arr) delete [] arr;
    return 0;
}
