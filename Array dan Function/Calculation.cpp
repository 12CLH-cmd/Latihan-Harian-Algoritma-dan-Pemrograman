#include <iostream>
using namespace std;

void input(double &a, double &b){
    cin >> a;
    cin >> b;
}

double tambah(double a, double b){
    return a + b;
}

double kurang(double a , double b){
    return a - b;
}

double kali(double a, double b){
    return a * b;
}

double bagi(double a, double b){
    return a / b;
}



int main(){
    double a, b;
    input(a,b);
    cout << tambah(a, b) << endl;
    cout << kurang(a, b) << endl;
    cout << kali(a, b) << endl;
    cout << bagi(a, b) << endl;
    
}