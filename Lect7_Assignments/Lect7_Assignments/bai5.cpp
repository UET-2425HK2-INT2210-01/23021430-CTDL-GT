﻿#include <iostream>
using namespace std;

const int MAXN = 10; // Giới hạn độ dài n
int perm[MAXN];      // Mảng lưu hoán vị hiện tại
bool used[MAXN];     // Mảng đánh dấu số đã dùng

void generatePermutations(int pos, int n) {
    if (pos == n) {
        // In hoán vị
        for (int i = 0; i < n; ++i) {
            cout << perm[i];
        }
        cout << endl;
        return;
    }

    // Thử tất cả các số từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) { // Nếu số i chưa được dùng
            used[i] = true;    // Đánh dấu đã dùng
            perm[pos] = i;     // Thêm i vào hoán vị
            generatePermutations(pos + 1, n); // Đệ quy tiếp
            used[i] = false;   // Bỏ đánh dấu để thử số khác
        }
    }
}

void listPermutations() {
    int n;
    cin >> n;

    // Khởi tạo mảng used
    for (int i = 0; i <= n; ++i) {
        used[i] = false;
    }

    generatePermutations(0, n);
}

int main() {
    listPermutations();
    return 0;
}