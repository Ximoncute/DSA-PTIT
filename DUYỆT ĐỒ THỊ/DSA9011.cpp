#include<iostream>
#include<vector>
using namespace std;

// 8 hướng di chuyển (lên, xuống, trái, phải và 4 đường chéo)
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int x, int y, vector<vector<int>>& A, vector<vector<bool>>& visited, int N, int M) {
    visited[x][y] = true;
    
    // Kiểm tra 8 hướng xung quanh
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Kiểm tra tọa độ hợp lệ
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            // Nếu là đất (1) và chưa được thăm
            if(A[nx][ny] == 1 && !visited[nx][ny]) {
                DFS(nx, ny, A, visited, N, M);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N, M;
        cin >> N >> M;
        
        // Khởi tạo ma trận và mảng visited
        vector<vector<int>> A(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        // Đọc ma trận
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        
        // Đếm số lượng hòn đảo
        int islandCount = 0;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                // Nếu tìm thấy đất (1) chưa được thăm
                if(A[i][j] == 1 && !visited[i][j]) {
                    // Tìm thấy một hòn đảo mới
                    DFS(i, j, A, visited, N, M);
                    islandCount++;
                }
            }
        }
        
        cout << islandCount << "\n";
    }
    
    return 0;
} 