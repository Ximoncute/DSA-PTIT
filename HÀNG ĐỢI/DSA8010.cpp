#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int u = i;
            int v = n / i;
            if (u > 1 && v > 1) {
                divisors.push_back(max(u, v));
            }
        }
    }
    return divisors;
}

int minSteps(int n) {
    if (n == 1) return 0;
    
    queue<pair<int, int>> q; // {current_value, steps}
    unordered_map<int, bool> visited;
    
    q.push({n, 0});
    visited[n] = true;
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Thao tác (a): Trừ 1
        if (current - 1 == 1) {
            return steps + 1;
        }
        if (current - 1 > 1 && visited.find(current - 1) == visited.end()) {
            visited[current - 1] = true;
            q.push({current - 1, steps + 1});
        }
        
        // Thao tác (b): N = max(u,v) với u*v = N
        vector<int> divisors = getDivisors(current);
        for (int div : divisors) {
            if (div == 1) {
                return steps + 1;
            }
            if (div > 1 && visited.find(div) == visited.end()) {
                visited[div] = true;
                q.push({div, steps + 1});
            }
        }
    }
    
    return -1; // Không tìm thấy (không xảy ra)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        cout << minSteps(N) << endl;
    }
    
    return 0;
} 