#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// 8 hướng di chuyển của quân mã
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int minKnightMoves(string start, string end) {
    if (start == end) return 0;
    
    // Chuyển đổi từ ký tự sang số
    int startX = start[0] - 'a';
    int startY = start[1] - '1';
    int endX = end[0] - 'a';
    int endY = end[1] - '1';
    
    // BFS
    queue<pair<pair<int, int>, int>> q; // {{x, y}, steps}
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    
    q.push({{startX, startY}, 0});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        
        // Thử 8 hướng di chuyển của quân mã
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(newX, newY) && !visited[newX][newY]) {
                if (newX == endX && newY == endY) {
                    return steps + 1;
                }
                
                visited[newX][newY] = true;
                q.push({{newX, newY}, steps + 1});
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
        string start, end;
        cin >> start >> end;
        cout << minKnightMoves(start, end) << endl;
    }
    
    return 0;
} 