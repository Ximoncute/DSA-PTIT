#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct State {
    int x, y;
    int dir;    // hướng hiện tại (0=right, 1=down, 2=left, 3=up)
    int turns;  // số lần đổi hướng
    
    State(int _x, int _y, int _dir, int _turns) {
        x = _x; y = _y; dir = _dir; turns = _turns;
    }
};

int dx[] = {0, 1, 0, -1}; // right, down, left, up
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y, int n, int m, vector<string>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '*';
}

bool solve(vector<string>& grid, int n, int m, int sx, int sy, int tx, int ty) {
    // visited[x][y][dir][turns] = đã thăm vị trí (x,y) với hướng dir và turns lần đổi hướng
    bool visited[505][505][4][3];
    memset(visited, false, sizeof(visited));
    
    queue<State> q;
    
    // Thử tất cả 4 hướng ban đầu
    for (int dir = 0; dir < 4; dir++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        
        if (isValid(nx, ny, n, m, grid)) {
            q.push(State(nx, ny, dir, 0));
            visited[nx][ny][dir][0] = true;
        }
    }
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        // Đến đích
        if (curr.x == tx && curr.y == ty) {
            return true;
        }
        
        // Tiếp tục đi thẳng (không đổi hướng)
        int nx = curr.x + dx[curr.dir];
        int ny = curr.y + dy[curr.dir];
        
        if (isValid(nx, ny, n, m, grid) && !visited[nx][ny][curr.dir][curr.turns]) {
            visited[nx][ny][curr.dir][curr.turns] = true;
            q.push(State(nx, ny, curr.dir, curr.turns));
        }
        
        // Đổi hướng (nếu chưa đổi quá 2 lần)
        if (curr.turns < 2) {
            for (int newDir = 0; newDir < 4; newDir++) {
                if (newDir == curr.dir) continue; // không đổi sang cùng hướng
                
                nx = curr.x + dx[newDir];
                ny = curr.y + dy[newDir];
                
                if (isValid(nx, ny, n, m, grid) && !visited[nx][ny][newDir][curr.turns + 1]) {
                    visited[nx][ny][newDir][curr.turns + 1] = true;
                    q.push(State(nx, ny, newDir, curr.turns + 1));
                }
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        int sx, sy, tx, ty;
        
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') {
                    sx = i; sy = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'T') {
                    tx = i; ty = j;
                    grid[i][j] = '.';
                }
            }
        }
        
        if (solve(grid, n, m, sx, sy, tx, ty)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 