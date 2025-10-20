#include <iostream>
using namespace std;

bool containDupe(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false; 
}

int main() {
    int n;
    cin >> n; 

    int nums[n]; 
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    if (containDupe(nums, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}
