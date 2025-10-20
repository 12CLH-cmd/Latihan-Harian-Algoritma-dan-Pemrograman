#include <iostream>
using namespace std;

void nuker(int &a, int &b) {
    int tempo = a;
    a = b;
    b = tempo;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                nuker(arr[j], arr[j + 1]);
            }
        }
    }
}

void hasilArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    hasilArray(arr, n);
}

