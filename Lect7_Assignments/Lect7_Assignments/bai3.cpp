﻿#include <iostream>
using namespace std;

// Hàm đệ quy tìm UCLN
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void findGCD() {
    int x, y;
    cin >> x >> y;
    // Đảm bảo số dương để xử lý trường hợp âm
    x = (x < 0) ? -x : x;
    y = (y < 0) ? -y : y;
    cout << gcd(x, y) << endl;
}

int main() {
    findGCD();
    return 0;
}