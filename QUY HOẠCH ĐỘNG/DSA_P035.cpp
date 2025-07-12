#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(const vector<vector<pair<int, long long>>>& graph, int start, int n) {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> cities(K);
    for (int i = 0; i < K; i++) {
        cin >> cities[i];
        cities[i]--; // Convert to 0-indexed
    }
    
    // Build adjacency list
    vector<vector<pair<int, long long>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        u--; v--; // Convert to 0-indexed
        graph[u].push_back({v, c});
    }
    
    // Compute shortest paths from city 0 and all required cities
    vector<int> important_cities = {0};
    for (int city : cities) {
        important_cities.push_back(city);
    }
    
    vector<vector<long long>> dist(N);
    for (int city : important_cities) {
        dist[city] = dijkstra(graph, city, N);
    }
    
    // Check if all required cities are reachable from city 0 and vice versa
    for (int i = 0; i < K; i++) {
        if (dist[0][cities[i]] == INF || dist[cities[i]][0] == INF) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    // DP with bitmask
    // dp[mask][i] = minimum cost to visit cities in mask and end at city i
    vector<vector<long long>> dp(1 << K, vector<long long>(K, INF));
    
    // Initialize: start from city 0, visit each city directly
    for (int i = 0; i < K; i++) {
        dp[1 << i][i] = dist[0][cities[i]];
    }
    
    // Fill DP table
    for (int mask = 0; mask < (1 << K); mask++) {
        for (int i = 0; i < K; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;
            
            for (int j = 0; j < K; j++) {
                if (mask & (1 << j)) continue; // Already visited
                
                int new_mask = mask | (1 << j);
                dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + dist[cities[i]][cities[j]]);
            }
        }
    }
    
    // Find minimum cost to visit all cities and return to city 0
    long long result = INF;
    int full_mask = (1 << K) - 1;
    
    for (int i = 0; i < K; i++) {
        if (dp[full_mask][i] != INF) {
            result = min(result, dp[full_mask][i] + dist[cities[i]][0]);
        }
    }
    
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
} 