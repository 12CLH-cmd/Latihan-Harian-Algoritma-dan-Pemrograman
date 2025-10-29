#include <iostream> 
using namespace std;

double rataRata(int *ptr, int  n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += *(ptr + i);
    }
    return total / n;
}

int main () {
    int n;
    int data[n];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    double rata = rataRata(data, n);
    cout << rata << endl;
    return 0;
}