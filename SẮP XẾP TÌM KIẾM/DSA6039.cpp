#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        unordered_map<int, int> count;
        unordered_map<int, int> first_index;

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            count[A[i]]++;
            if (first_index.find(A[i]) == first_index.end()) {
                first_index[A[i]] = i; // chỉ lưu vị trí đầu tiên
            }
        }

        int min_index = N + 1;
        int result = -1;

        for (auto &kv : count) {
            if (kv.second > 1) {
                int val = kv.first;
                int idx = first_index[val];
                if (idx < min_index) {
                    min_index = idx;
                    result = val;
                }
            }
        }

        if (result == -1) cout << "NO\n";
        else cout << result << "\n";
    }
    return 0;
}