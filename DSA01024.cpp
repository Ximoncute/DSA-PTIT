#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
vector<string> names, comb;

void backtrack(int start, int depth) {
    if (depth == K) {
        for (int i = 0; i < K; ++i) {
            if (i) cout << " ";
            cout << comb[i];
        }
        cout << endl;
        return;
    }
    for (int i = start; i < names.size(); ++i) {
        comb[depth] = names[i];
        backtrack(i + 1, depth + 1);
    }
}

int main() {
    cin >> N >> K;
    set<string> s;
    for (int i = 0; i < N; ++i) {
        string x; cin >> x;
        s.insert(x);
    }
    names.assign(s.begin(), s.end());
    sort(names.begin(), names.end());
    comb.resize(K);
    backtrack(0, 0);
    return 0;
}