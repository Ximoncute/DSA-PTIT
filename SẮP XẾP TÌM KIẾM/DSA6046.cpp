#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        long long min_diff = LLONG_MAX;
        for (int i = 1; i < N; ++i) {
            min_diff = min(min_diff, A[i] - A[i - 1]);
        }

        // Nếu chỉ có 1 phần tử, không thể tìm 2 phần tử để tính chênh lệch
        if (N < 2) cout << 0 << endl;
        else cout << min_diff << endl;
    }

    return 0;
}
