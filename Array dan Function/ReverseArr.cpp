#include <iostream>
using namespace std;

void rev(int n) {
    string s;
    cin >> s;

    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
}

int main () {
    int n;
    rev(n);
}