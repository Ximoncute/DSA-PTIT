#include <stdio.h>

#define INF 1000000000
#define MAXV 1005
#define MAXE 500005

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAXE];
int dist[MAXV];
int V, E;

int bellmanFord() {
    // Khởi tạo khoảng cách
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    
    // Chọn đỉnh bắt đầu (có thể là bất kỳ đỉnh nào)
    dist[1] = 0;
    
    // Relax các cạnh V-1 lần
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Kiểm tra chu trình âm
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;
        
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 1; // Có chu trình âm
        }
    }
    
    return 0; // Không có chu trình âm
}

int hasNegativeCycle() {
    // Thử với mọi đỉnh làm điểm bắt đầu để đảm bảo kiểm tra toàn bộ đồ thị
    for (int start = 1; start <= V; start++) {
        // Khởi tạo khoảng cách
        for (int i = 1; i <= V; i++) {
            dist[i] = INF;
        }
        dist[start] = 0;
        
        // Relax các cạnh V-1 lần
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].u;
                int v = edges[j].v;
                int w = edges[j].weight;
                
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Kiểm tra chu trình âm
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return 1; // Có chu trình âm
            }
        }
    }
    
    return 0; // Không có chu trình âm
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &V, &E);
        
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }
        
        printf("%d\n", hasNegativeCycle());
    }
    
    return 0;
} 