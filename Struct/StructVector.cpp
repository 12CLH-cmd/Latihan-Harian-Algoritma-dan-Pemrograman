#include <iostream>
using namespace std;

struct Vector2 {
    float x;
    float y;
};

float dot(Vector2 a, Vector2 b) {
    return a.x*b.x + a.y*b.y;
}

float magn(float x) {
    float r = x;
    float prev;
    do {
        prev = r;
        r = (r + x / r) / 2.0f;
    } while(r - prev > 0.0001f || prev - r > 0.0001f);
    return r;
}

float magnitude(Vector2 v) {
    return magn(v.x*v.x + v.y*v.y);
}

int main() {
    Vector2 v[3];
    for (int i = 0; i < 3; i++) {
        cout << "Vector " << i+1 << " (x y): ";
        cin >> v[i].x >> v[i].y;
    }

    int idx = 0;
    float mmax = magnitude(v[0]);

    for (int i = 1; i < 3; i++) {
        float m = magnitude(v[i]);
        if (m > mmax) {
            mmax = m;
            idx = i;
        }
    }

    cout << "\nVector terbesar magnitude: (" << v[idx].x << ", " << v[idx].y << ")\n";
}
