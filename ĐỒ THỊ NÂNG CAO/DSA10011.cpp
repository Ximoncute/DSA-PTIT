#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000
#define MAXN 505

int A[MAXN][MAXN];
int dist[MAXN][MAXN];
int visited[MAXN][MAXN];
int n, m;

// Các hướng di chuyển: lên, xuống, trái, phải
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y, cost;
};

// Priority queue đơn giản dùng mảng
struct Node pq[MAXN * MAXN];
int pq_size;

void push(int x, int y, int cost) {
    pq[pq_size].x = x;
    pq[pq_size].y = y;
    pq[pq_size].cost = cost;
    pq_size++;
    
    // Bubble up
    int idx = pq_size - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq[parent].cost <= pq[idx].cost) break;
        
        struct Node temp = pq[parent];
        pq[parent] = pq[idx];
        pq[idx] = temp;
        idx = parent;
    }
}

struct Node pop() {
    struct Node result = pq[0];
    pq_size--;
    
    if (pq_size > 0) {
        pq[0] = pq[pq_size];
        
        // Bubble down
        int idx = 0;
        while (1) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            
            if (left < pq_size && pq[left].cost < pq[smallest].cost) {
                smallest = left;
            }
            if (right < pq_size && pq[right].cost < pq[smallest].cost) {
                smallest = right;
            }
            
            if (smallest == idx) break;
            
            struct Node temp = pq[idx];
            pq[idx] = pq[smallest];
            pq[smallest] = temp;
            idx = smallest;
        }
    }
    
    return result;
}

int isEmpty() {
    return pq_size == 0;
}

int dijkstra() {
    // Khởi tạo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
            visited[i][j] = 0;
        }
    }
    
    pq_size = 0;
    dist[0][0] = A[0][0];
    push(0, 0, A[0][0]);
    
    while (!isEmpty()) {
        struct Node current = pop();
        int x = current.x;
        int y = current.y;
        int cost = current.cost;
        
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        
        if (x == n-1 && y == m-1) {
            return cost;
        }
        
        // Kiểm tra 4 hướng
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                int newCost = cost + A[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    push(nx, ny, newCost);
                }
            }
        }
    }
    
    return dist[n-1][m-1];
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        
        printf("%d\n", dijkstra());
    }
    
    return 0;
} 