#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Point3D {
    int x, y, z, steps;
    Point3D(int x, int y, int z, int steps) : x(x), y(y), z(z), steps(steps) {}
};

// 6 hướng di chuyển trong không gian 3D (không đi chéo)
int dx[] = {-1, 1, 0, 0, 0, 0}; // lên, xuống, không thay đổi
int dy[] = {0, 0, -1, 1, 0, 0}; // không thay đổi, trái, phải
int dz[] = {0, 0, 0, 0, -1, 1}; // không thay đổi, trước, sau

bool isValid(int x, int y, int z, int A, int B, int C) {
    return x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C;
}

int findShortestPath(vector<vector<string>>& grid, int A, int B, int C) {
    // Tìm vị trí bắt đầu S và kết thúc E
    int startX = -1, startY = -1, startZ = -1;
    int endX = -1, endY = -1, endZ = -1;
    
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < C; k++) {
                if (grid[i][j][k] == 'S') {
                    startX = i; startY = j; startZ = k;
                } else if (grid[i][j][k] == 'E') {
                    endX = i; endY = j; endZ = k;
                }
            }
        }
    }
    
    // Nếu không tìm thấy S hoặc E
    if (startX == -1 || endX == -1) return -1;
    
    // BFS
    queue<Point3D> q;
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    
    q.push(Point3D(startX, startY, startZ, 0));
    visited[startX][startY][startZ] = true;
    
    while (!q.empty()) {
        Point3D current = q.front();
        q.pop();
        
        // Nếu đã đến đích
        if (current.x == endX && current.y == endY && current.z == endZ) {
            return current.steps;
        }
        
        // Thử 6 hướng di chuyển
        for (int i = 0; i < 6; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            int newZ = current.z + dz[i];
            
            if (isValid(newX, newY, newZ, A, B, C) && !visited[newX][newY][newZ]) {
                // Kiểm tra không phải vật cản
                if (grid[newX][newY][newZ] != '#') {
                    visited[newX][newY][newZ] = true;
                    q.push(Point3D(newX, newY, newZ, current.steps + 1));
                }
            }
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
        int A, B, C;
        cin >> A >> B >> C;
        
        vector<vector<string>> grid(A, vector<string>(B));
        
        // Đọc dữ liệu
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                cin >> grid[i][j];
            }
        }
        
        cout << findShortestPath(grid, A, B, C) << endl;
    }
    
    return 0;
} 