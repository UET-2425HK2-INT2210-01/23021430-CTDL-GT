﻿#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 1000;
const int INF = 1000000;     // Giá trị lớn để biểu diễn vô cực
int dist[MAX_N];             // Mảng khoảng cách
int graph[MAX_N][MAX_N];     // Ma trận kề lưu trọng số (mức độ ô nhiễm)
int nextNode[MAX_N];         // Mảng để lưu vết đường đi
int n, m, s, e;

// Bellman-Ford để tìm đường đi ngắn nhất từ s đến e
bool BellmanFord(int start) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        nextNode[i] = -1;
    }
    dist[start] = 0;

    for (int k = 1; k < n; ++k) {
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (graph[u][v] != INF && dist[u] != INF) {
                    if (dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        nextNode[v] = u; // Lưu vết
                    }
                }
            }
        }
    }

    // Kiểm tra chu trình âm
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                return false; // Phát hiện chu trình âm
            }
        }
    }
    return true;
}

// Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất cho mọi cặp
void FloydWarshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

// Hàm truy vết đường đi ngắn nhất từ s đến e
void printPath(int s, int e, ofstream& outfile) {
    if (dist[e] == INF) {
        outfile << "No path found" << endl;
        return;
    }

    int current = e;
    int path[MAX_N];
    int idx = 0;

    while (current != -1) {
        path[idx++] = current;
        current = nextNode[current];
    }

    // In ra đường đi theo thứ tự ngược lại
    for (int i = idx - 1; i >= 0; --i) {
        outfile << path[i];
        if (i > 0) outfile << " ";
    }
    outfile << endl;
}

int main() {
    // Khởi tạo
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 1; j <= MAX_N; ++j) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Đọc dữ liệu từ file input.txt
    ifstream infile("F:\\CODE\\input.txt");
    ofstream outfile("F:\\CODE\\output.txt");
    infile >> n >> m >> s >> e;

    // Nhập các cạnh và trọng số
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        infile >> u >> v >> w;
        graph[u][v] = w;
    }

    // Thực hiện Bellman-Ford
    if (BellmanFord(s)) {
        if (dist[e] == INF) {
            outfile << "No path found" << endl;
        }
        else {
            outfile << dist[e] << endl;
            printPath(s, e, outfile);
        }
    }
    else {
        outfile << "Negative cycle detected!" << endl;
    }

    // Thực hiện Floyd-Warshall cho tất cả cặp đỉnh
    FloydWarshall();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j] == INF)
                outfile << "INF ";
            else
                outfile << graph[i][j] << " ";
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
