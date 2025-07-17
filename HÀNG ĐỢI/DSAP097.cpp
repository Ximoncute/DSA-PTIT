#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(pii start, pii end, map<int, set<int>>& grid) {
    queue<pair<pii, int>> q;
    set<pii> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, dist] = q.front(); q.pop();
        if (cur == end) return dist;

        for (int i = 0; i < 8; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (grid.count(nx) && grid[nx].count(ny)) {
                pii next = {nx, ny};
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;

        int N;
        cin >> N;
        map<int, set<int>> grid;

        for (int i = 0; i < N; ++i) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; ++y) {
                grid[x].insert(y);
            }
        }

        pii start = {xa, ya}, end = {xb, yb};
        if (!grid.count(xa) || !grid[xa].count(ya) || !grid.count(xb) || !grid[xb].count(yb)) {
            cout << -1 << '\n';
            continue;
        }

        cout << bfs(start, end, grid) << '\n';
    }

    return 0;
}
