#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<string> paths;
string currentPath;

// Các hướng di chuyển: Down, Left, Right, Up (theo thứ tự từ điển)
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char direction[] = {'D', 'L', 'R', 'U'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && 
           maze[x][y] == 1 && !visited[x][y];
}

void findPaths(int x, int y) {
    // Nếu đến đích
    if (x == n-1 && y == n-1) {
        paths.push_back(currentPath);
        return;
    }
    
    // Thử tất cả 4 hướng
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (isValid(newX, newY)) {
            visited[newX][newY] = true;
            currentPath += direction[i];
            
            findPaths(newX, newY);
            
            // Backtrack
            currentPath.pop_back();
            visited[newX][newY] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        // Khởi tạo ma trận
        maze.assign(n, vector<int>(n));
        visited.assign(n, vector<bool>(n, false));
        paths.clear();
        currentPath = "";
        
        // Đọc ma trận
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        
        // Kiểm tra nếu ô đầu hoặc ô cuối = 0
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) {
            cout << -1 << endl;
            continue;
        }
        
        // Bắt đầu tìm đường
        visited[0][0] = true;
        findPaths(0, 0);
        
        if (paths.empty()) {
            cout << -1 << endl;
        } else {
            sort(paths.begin(), paths.end());
            for (int i = 0; i < paths.size(); i++) {
                cout << paths[i];
                if (i < paths.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
} 