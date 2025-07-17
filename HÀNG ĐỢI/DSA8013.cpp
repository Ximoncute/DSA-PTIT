#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Point {
    int x, y, steps;
    Point(int x, int y, int steps) : x(x), y(y), steps(steps) {}
};

int minSteps(vector<string>& grid, int startX, int startY, int endX, int endY) {
    int n = grid.size();
    
    if (startX == endX && startY == endY) return 0;
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Point> q;
    
    q.push(Point(startX, startY, 0));
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // Di chuyển theo hàng (cùng x, thay đổi y)
        for (int newY = 0; newY < n; newY++) {
            if (newY == current.y) continue; // Bỏ qua vị trí hiện tại
            
            // Kiểm tra có vật cản giữa current.y và newY không
            bool hasObstacle = false;
            int minY = min(current.y, newY);
            int maxY = max(current.y, newY);
            
            for (int y = minY + 1; y < maxY; y++) {
                if (grid[current.x][y] == 'X') {
                    hasObstacle = true;
                    break;
                }
            }
            
            if (!hasObstacle && grid[current.x][newY] == '.' && !visited[current.x][newY]) {
                if (current.x == endX && newY == endY) {
                    return current.steps + 1;
                }
                
                visited[current.x][newY] = true;
                q.push(Point(current.x, newY, current.steps + 1));
            }
        }
        
        // Di chuyển theo cột (cùng y, thay đổi x)
        for (int newX = 0; newX < n; newX++) {
            if (newX == current.x) continue; // Bỏ qua vị trí hiện tại
            
            // Kiểm tra có vật cản giữa current.x và newX không
            bool hasObstacle = false;
            int minX = min(current.x, newX);
            int maxX = max(current.x, newX);
            
            for (int x = minX + 1; x < maxX; x++) {
                if (grid[x][current.y] == 'X') {
                    hasObstacle = true;
                    break;
                }
            }
            
            if (!hasObstacle && grid[newX][current.y] == '.' && !visited[newX][current.y]) {
                if (newX == endX && current.y == endY) {
                    return current.steps + 1;
                }
                
                visited[newX][current.y] = true;
                q.push(Point(newX, current.y, current.steps + 1));
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
        int N;
        cin >> N;
        
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        cout << minSteps(grid, a, b, c, d) << endl;
    }
    
    return 0;
} 