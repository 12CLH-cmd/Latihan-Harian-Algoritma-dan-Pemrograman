#include <iostream>
using namespace std;

struct Stack {
    int data[100];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }
        top++;
        data[top] = x;
        cout << "Push: " << x << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Pop: " << data[top] << endl;
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Top element: " << data[top] << endl;
    }
};

int main() {
    Stack s;
    int pilihan, x;

    do {
        cout << "\n=== MENU STACK ===\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Peek (Top)\n"
             << "4. Cek Kosong\n"
             << "5. Cek Penuh\n"
             << "0. Keluar\n"
             << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan angka: ";
            cin >> x;
            s.push(x);
        }
        else if (pilihan == 2) {
            s.pop();
        }
        else if (pilihan == 3) {
            s.peek();
        }
        else if (pilihan == 4) {
            cout << (s.isEmpty() ? "Stack kosong\n" : "Stack tidak kosong\n");
        }
        else if (pilihan == 5) {
            cout << (s.isFull() ? "Stack penuh\n" : "Stack tidak penuh\n");
        }

    } while (pilihan != 0);

    return 0;
}
