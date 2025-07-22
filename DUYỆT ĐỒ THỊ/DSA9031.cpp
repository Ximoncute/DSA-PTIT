#include <iostream>
#include <vector>
#include <set>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    
    // Lưu trữ các hàng rào
    set<pair<pair<int, int>, pair<int, int>>> fences;
    
    for (int i = 0; i < M; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        pair<int, int> p1 = {u, v};
        pair<int, int> p2 = {x, y};
        if (p1 > p2) swap(p1, p2);
        fences.insert({p1, p2});
    }
    
    // Chuyển đổi tọa độ (i, j) thành index
    auto getIndex = [&](int i, int j) -> int {
        return (i - 1) * N + (j - 1);
    };
    
    // Khởi tạo Union-Find cho tất cả các ô
    UnionFind uf(N * N);
    
    // Kết nối các ô không bị ngăn cách bởi hàng rào
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni < 1 || ni > N || nj < 1 || nj > N) continue;
                
                // Kiểm tra có hàng rào không
                pair<int, int> p1 = {i, j};
                pair<int, int> p2 = {ni, nj};
                if (p1 > p2) swap(p1, p2);
                
                if (fences.find({p1, p2}) == fences.end()) {
                    // Không có hàng rào, kết nối hai ô
                    uf.unite(getIndex(i, j), getIndex(ni, nj));
                }
            }
        }
    }
    
    // Đọc vị trí các chú cừu
    vector<pair<int, int>> sheep(K);
    for (int i = 0; i < K; i++) {
        cin >> sheep[i].first >> sheep[i].second;
    }
    
    // Đếm số cặp chú cừu xa cách
    int count = 0;
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            int idx1 = getIndex(sheep[i].first, sheep[i].second);
            int idx2 = getIndex(sheep[j].first, sheep[j].second);
            
            if (!uf.connected(idx1, idx2)) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
} 