#include <iostream>
using namespace std;

int n, m;
char a[1005][1005];
bool visited[1005][1005];

void dfs(int x, int y) {
    visited[x][y] = true;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && a[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#' && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
    cout << cnt << endl;
    return 0;
}