#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y, day;
    Point(int x, int y, int day) : x(x), y(y), day(day) {}
};

int dx[] = {-1, 1, 0, 0}; // lên, xuống, trái, phải
int dy[] = {0, 0, -1, 1};

int minDaysToRipen(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    
    queue<Point> q;
    int totalSeeds = 0; // Tổng số hạt mầm chưa nảy mầm
    
    // Đếm tổng số hạt mầm chưa nảy mầm và thêm các cây non ban đầu vào queue
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1) {
                totalSeeds++;
            } else if (grid[i][j] == 2) {
                q.push(Point(i, j, 0));
            }
        }
    }
    
    // Nếu không có hạt mầm nào, trả về 0
    if (totalSeeds == 0) return 0;
    
    int maxDay = 0;
    int ripenedCount = 0; // Số hạt mầm đã được chuyển đổi
    
    // BFS
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // Kiểm tra 4 hướng xung quanh
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            // Kiểm tra biên
            if (newX >= 0 && newX < R && newY >= 0 && newY < C) {
                // Nếu là hạt mầm chưa nảy mầm
                if (grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Chuyển thành cây non
                    ripenedCount++;
                    maxDay = max(maxDay, current.day + 1);
                    q.push(Point(newX, newY, current.day + 1));
                }
            }
        }
    }
    
    // Kiểm tra xem tất cả hạt mầm đã nảy mầm chưa
    if (ripenedCount == totalSeeds) {
        return maxDay;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int R, C;
        cin >> R >> C;
        
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }
        
        cout << minDaysToRipen(grid) << endl;
    }
    
    return 0;
} 