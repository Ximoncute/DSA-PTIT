#include <stdio.h>

#define INF 1000000000
#define MAXN 105

int dist[MAXN][MAXN];
int n, m;

void floydWarshall() {
    // Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
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

double calculateAverageDistance() {
    int totalDistance = 0;
    int count = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && dist[i][j] != INF) {
                totalDistance += dist[i][j];
                count++;
            }
        }
    }
    
    if (count == 0) return 0.0;
    return (double)totalDistance / count;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
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
            int u, v;
            scanf("%d %d", &u, &v);
            dist[u][v] = 1; // Cạnh có trọng số 1
        }
        
        // Chạy Floyd-Warshall
        floydWarshall();
        
        // Tính khoảng cách trung bình
        double avgDistance = calculateAverageDistance();
        
        printf("%.2f\n", avgDistance);
    }
    
    return 0;
} 