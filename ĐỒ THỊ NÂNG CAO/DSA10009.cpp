#include <stdio.h>
#include <limits.h>

#define INF 1000000000
#define MAXN 105

int dist[MAXN][MAXN];

void floydWarshall(int n) {
    // Thuật toán Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    
    // Đọc các cạnh
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        dist[u][v] = c;
        dist[v][u] = c; // Đồ thị vô hướng
    }
    
    // Chạy Floyd-Warshall
    floydWarshall(n);
    
    // Xử lý các truy vấn
    int q;
    scanf("%d", &q);
    
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", dist[x][y]);
    }
    
    return 0;
} 