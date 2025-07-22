#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const ll inf = LLONG_MAX;

void solve() {
  int n, m, x; cin >> n >> m >> x;
  vector<pair<int, ll>> adj[n + 1];

  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  
  ll dist[n + 1];
  for (int i = 1; i <= n; ++i) dist[i] = inf;
  dist[x] = 0;
  
  priority_queue<pair<ll, int>> q; bool vis[n + 1] = {};
  q.push({0, x});
  while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (vis[a]) continue;
    vis[a] = true;

    for (auto p: adj[a]) {
      int b = p.first;
      ll w = p.second;
      if (dist[b] > w + dist[a]) {
        dist[b] = w + dist[a];
        q.push({-dist[b], b});
      }
    }
  }

  for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}