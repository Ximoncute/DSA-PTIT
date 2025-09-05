#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int s1, s2, f1, f2;
    cin >> s1 >> s2 >> f1 >> f2;
    s1--; s2--; f1--; f2--;

    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;
    q.emplace(s1, s2);
    dist[s1][s2] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == f1 && y == f2) {
            cout << dist[x][y] << '\n';
            return 0;
        }
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    return 0;
}
