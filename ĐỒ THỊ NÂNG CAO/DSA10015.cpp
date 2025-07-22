#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

int parent[105], rank_arr[105];

void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
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
    
    if (rank_arr[px] < rank_arr[py]) {
        parent[px] = py;
    } else if (rank_arr[px] > rank_arr[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank_arr[px]++;
    }
    return 1;
}

int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int kruskal(int V, struct Edge edges[], int E) {
    qsort(edges, E, sizeof(struct Edge), compare);
    
    makeSet(V);
    int mstWeight = 0;
    int edgesUsed = 0;
    
    for (int i = 0; i < E; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            mstWeight += edges[i].weight;
            edgesUsed++;
            if (edgesUsed == V - 1) break;
        }
    }
    
    return mstWeight;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        struct Edge edges[10005];
        
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }
        
        printf("%d\n", kruskal(V, edges, E));
    }
    
    return 0;
} 