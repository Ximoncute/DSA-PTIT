#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Kiểm tra 2 từ khác nhau đúng 1 ký tự
bool oneCharDiff(const string& a, const string& b) {
    int diff = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++diff;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

int bfs(string s, string t, unordered_set<string>& dict) {
    if (s == t) return 0;
    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({s, 1});
    visited.insert(s);

    while (!q.empty()) {
        auto [cur, steps] = q.front(); q.pop();
        for (size_t i = 0; i < cur.size(); ++i) {
            string next = cur;
            for (char c = 'A'; c <= 'Z'; ++c) {
                if (c == cur[i]) continue;
                next[i] = c;
                if (dict.count(next) && !visited.count(next)) {
                    if (next == t) return steps + 1;
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
    }

    return -1; // Không tìm được đường đi
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        stringstream ss1(line1), ss2(line2);
        int n;
        string s, t;
        ss1 >> n >> s >> t;

        unordered_set<string> dict;
        string word;
        while (ss2 >> word) {
            dict.insert(word);
        }

        int res = bfs(s, t, dict);
        cout << res << endl;
    }

    return 0;
}
