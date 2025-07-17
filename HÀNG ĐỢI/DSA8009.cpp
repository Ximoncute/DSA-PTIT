#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minSteps(int S, int T) {
    if (S == T) return 0;
    if (S > T) return S - T; // Chỉ có thể trừ 1
    
    queue<pair<int, int>> q; // {current_value, steps}
    vector<bool> visited(20001, false); // Giới hạn để tránh overflow
    
    q.push({S, 0});
    visited[S] = true;
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Thao tác (a): Trừ 1
        if (current - 1 >= 0 && !visited[current - 1]) {
            if (current - 1 == T) {
                return steps + 1;
            }
            visited[current - 1] = true;
            q.push({current - 1, steps + 1});
        }
        
        // Thao tác (b): Nhân 2
        if (current * 2 <= 20000 && !visited[current * 2]) {
            if (current * 2 == T) {
                return steps + 1;
            }
            visited[current * 2] = true;
            q.push({current * 2, steps + 1});
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
        int S, target;
        cin >> S >> target;
        cout << minSteps(S, target) << endl;
    }
    
    return 0;
} 