#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 8 hướng
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int x, int y, int N, int M) {
    visited[x][y] = true;
    
    // Duyệt 8 hướng
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Kiểm tra biên
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            // Nếu là ô nước và chưa thăm
            if (grid[nx][ny] == 'W' && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny, N, M);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> grid(N);
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    // Đọc dữ liệu
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    int count = 0;
    
    // Duyệt tất cả các ô
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Nếu là ô nước và chưa thăm
            if (grid[i][j] == 'W' && !visited[i][j]) {
                // Tìm thấy một ao mới
                count++;
                dfs(grid, visited, i, j, N, M);
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
} 