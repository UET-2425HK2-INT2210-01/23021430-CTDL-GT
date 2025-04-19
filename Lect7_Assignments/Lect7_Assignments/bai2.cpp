﻿#include <iostream>
using namespace std;

const int MAXM = 100; // Giới hạn số dòng
const int MAXN = 100; // Giới hạn số cột

void findMaxRectangle() {
    int m, n;
    int matrix[MAXM][MAXN];
    long long prefixSum[MAXM + 1][MAXN + 1] = { 0 };

    // Nhập m, n và ma trận
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tính tổng tích lũy
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    // Tìm hình chữ nhật có tổng lớn nhất
    long long maxSum = -1e18; // Giá trị nhỏ để bắt đầu
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    for (int i1 = 0; i1 < m; ++i1) {
        for (int j1 = 0; j1 < n; ++j1) {
            for (int i2 = i1; i2 < m; ++i2) {
                for (int j2 = j1; j2 < n; ++j2) {
                    // Tính tổng hình chữ nhật từ (i1,j1) đến (i2,j2)
                    long long sum = prefixSum[i2 + 1][j2 + 1] - prefixSum[i2 + 1][j1] - prefixSum[i1][j2 + 1] + prefixSum[i1][j1];
                    if (sum > maxSum) {
                        maxSum = sum;
                        r1 = i1 + 1; // Chuyển về chỉ số 1-based
                        c1 = j1 + 1;
                        r2 = i2 + 1;
                        c2 = j2 + 1;
                    }
                }
            }
        }
    }

    // In kết quả
    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;
}

int main() {
    findMaxRectangle();
    return 0;
}