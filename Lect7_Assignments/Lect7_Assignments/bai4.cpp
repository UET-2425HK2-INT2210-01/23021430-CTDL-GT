﻿#include <iostream>
using namespace std;

const int MAXN = 20;
int binary[MAXN];

void generateBinary(int pos, int n) {
    if (pos == n) {
        // In số nhị phân
        for (int i = 0; i < n; ++i) {
            cout << binary[i];
        }
        cout << endl;
        return;
    }

    // Thử đặt 0 hoặc 1 tại vị trí pos
    binary[pos] = 0;
    generateBinary(pos + 1, n);
    binary[pos] = 1;
    generateBinary(pos + 1, n);
}

void listBinaryNumbers() {
    int n;
    cin >> n;
    generateBinary(0, n);
}

int main() {
    listBinaryNumbers();
    return 0;
}