#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 105

struct Point {
    double x, y;
};

struct Edge {
    int u, v;
    double weight;
};

struct Point points[MAXN];
struct Edge edges[MAXN * MAXN];
int parent[MAXN];
int N, edgeCount;

double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    
    if (px == py) return 0;
    
    parent[px] = py;
    return 1;
}

int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    
    if (edgeA->weight < edgeB->weight) return -1;
    if (edgeA->weight > edgeB->weight) return 1;
    return 0;
}

double kruskal() {
    // Tạo tất cả các cạnh có thể
    edgeCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges[edgeCount].u = i;
            edges[edgeCount].v = j;
            edges[edgeCount].weight = distance(points[i], points[j]);
            edgeCount++;
        }
    }
    
    // Sắp xếp các cạnh theo trọng số tăng dần
    qsort(edges, edgeCount, sizeof(struct Edge), compare);
    
    // Khởi tạo Union-Find
    makeSet(N);
    
    double totalCost = 0.0;
    int edgesUsed = 0;
    
    // Thuật toán Kruskal
    for (int i = 0; i < edgeCount && edgesUsed < N - 1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            totalCost += edges[i].weight;
            edgesUsed++;
        }
    }
    
    return totalCost;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        
        double result = kruskal();
        printf("%.6f\n", result);
    }
    
    return 0;
} 