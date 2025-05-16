﻿#include <iostream>
using namespace std;

const int MAX_N = 1000;     // Giới hạn số đỉnh tối đa
int adj[MAX_N][MAX_N];      // Ma trận kề để lưu đồ thị
int dist[MAX_N];            // Mảng khoảng cách
int queue[MAX_N];           // Hàng đợi thủ công
int front = 0, rear = 0;    // Con trỏ hàng đợi
int n, m, X, Y;             // Số đỉnh, số cạnh, điểm bắt đầu và kết thúc

// Thêm phần tử vào hàng đợi
void enqueue(int node) {
    queue[rear++] = node;
}

// Lấy phần tử ra khỏi hàng đợi
int dequeue() {
    return queue[front++];
}

// Hàm BFS để tìm đường đi ngắn nhất theo số cạnh
int BFS(int start, int end) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;  // Khởi tạo khoảng cách là -1 (chưa thăm)
    }
    enqueue(start);
    dist[start] = 0;

    while (front < rear) {
        int u = dequeue();
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                enqueue(v);
                if (v == end) {
                    return dist[v];
                }
            }
        }
    }
    return -1; // Không tìm thấy đường đi
}

int main() {
    cin >> n >> m >> X >> Y;

    // Nhập các cạnh vào ma trận kề
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Đồ thị có hướng
    }

    // Tìm đường đi ngắn nhất theo số cạnh
    int result = BFS(X, Y);
    cout << result << endl;

    return 0;
}
