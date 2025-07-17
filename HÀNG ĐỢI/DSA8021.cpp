#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findMinSteps(vector<vector<int>>& matrix, int m, int n) {
    if (m == 1 && n == 1) return 0;
    
    // BFS
    queue<pair<pair<int, int>, int>> q; // {{row, col}, steps}
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    q.push({{0, 0}, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        
        int value = matrix[row][col];
        
        // Nếu giá trị là 0, không thể di chuyển
        if (value == 0) continue;
        
        // Di chuyển sang phải: A[i][j+A[i][j]]
        int newCol = col + value;
        if (newCol < n && !visited[row][newCol]) {
            if (row == m - 1 && newCol == n - 1) {
                return steps + 1;
            }
            visited[row][newCol] = true;
            q.push({{row, newCol}, steps + 1});
        }
        
        // Di chuyển xuống dưới: A[i+A[i][j]][j]
        int newRow = row + value;
        if (newRow < m && !visited[newRow][col]) {
            if (newRow == m - 1 && col == n - 1) {
                return steps + 1;
            }
            visited[newRow][col] = true;
            q.push({{newRow, col}, steps + 1});
        }
    }
    
    return -1; // Không tìm thấy đường đi
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int M, N;
        cin >> M >> N;
        
        vector<vector<int>> matrix(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        
        cout << findMinSteps(matrix, M, N) << endl;
    }
    
    return 0;
} 