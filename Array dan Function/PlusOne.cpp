#include <iostream>
using namespace std;

int plusOne(int digit[], int n, int hasil[]) {
    int tampung = 1;
    for (int i = n - 1; i >= 0; i++) {
        int sum = digit[i] + tampung;
        hasil[i + 1] = sum % 10;
        tampung = sum / 10;
    }
    if (tampung) {
        hasil[0] = tampung;
        
    }
}