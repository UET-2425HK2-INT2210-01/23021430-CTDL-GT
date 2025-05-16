﻿#include <iostream>
using namespace std;
const int MAX_N = 1000;  // Giới hạn số đỉnh tối đa
int adj[MAX_N][MAX_N];   // Ma trận kề để lưu đồ thị
bool visited[MAX_N];     // Mảng đánh dấu đã thăm
int n, m;                // Số đỉnh và số cạnh
// Hàm DFS
void DFS(int node) {
    visited[node] = true;  // Đánh dấu đã thăm

    // Duyệt tất cả các đỉnh kề với node
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(i);  // Đệ quy tìm kiếm
        }
    }
}
// Hàm tính số lượng thành phần liên thông
int connectedComponents() {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {  // Nếu chưa thăm
            count++;         // Tăng số lượng thành phần liên thông
            DFS(i);          // Thực hiện DFS từ đỉnh này
        }
    }
    return count;
}
int main() {
    cin >> n >> m;
    // Khởi tạo ma trận kề và mảng visited
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            adj[i][j] = 0;  // Không có cạnh giữa các đỉnh
        }
        visited[i] = false;  // Đánh dấu các đỉnh chưa thăm
    }
    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;  // Thêm cạnh giữa u và v
        adj[v][u] = 1;  // Vì đồ thị không có hướng
    }
    // Tính số thành phần liên thông
    int result = connectedComponents();
    cout << result << endl;
    return 0;
}