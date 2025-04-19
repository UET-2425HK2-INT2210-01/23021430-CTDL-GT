﻿#include <iostream>
using namespace std;

const int MAXN = 1000; // Giới hạn số lượng số thực

void sortNumbers() {
    int n;
    double numbers[MAXN];

    // Nhập số lượng và danh sách số
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Sắp xếp nổi bọt (bubble sort)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // In kết quả
    for (int i = 0; i < n; ++i) {
        cout << numbers[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    sortNumbers();
    return 0;
}