#include <iostream>
using namespace std;

int shellSort (int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }  
            arr[j] = temp;
        }
    }
    return 0;
}

int main () {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    shellSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}