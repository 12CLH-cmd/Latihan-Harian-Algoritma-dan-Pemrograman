#include <iostream>
using namespace std;

int countMaks (int *ptr, int n) {
    int maks = *ptr;
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) > maks) {
            maks = *(ptr + i);
        }
    }
    return maks;
}

int main () {
    int n;
    cin >> n; 
    int data[n];

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << countMaks (data, n) << endl;
}

