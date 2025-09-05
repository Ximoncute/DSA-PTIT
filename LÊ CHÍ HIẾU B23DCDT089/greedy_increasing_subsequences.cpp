#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<bool> used(N, false);
    vector<vector<int>> subsequences;

    while (true) {
        int last = -1;
        vector<int> subseq;
        bool found = false;
        for (int i = 0; i < N; ++i) {
            if (!used[i] && a[i] > last) {
                subseq.push_back(a[i]);
                used[i] = true;
                last = a[i];
                found = true;
            }
        }
        if (!found) break;
        subsequences.push_back(subseq);
    }

    cout << subsequences.size() << '\n';
    for (size_t i = 0; i < subsequences.size(); ++i) {
        for (size_t j = 0; j < subsequences[i].size(); ++j) {
            cout << subsequences[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
