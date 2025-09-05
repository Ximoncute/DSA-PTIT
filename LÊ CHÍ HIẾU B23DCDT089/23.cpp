#include <bits/stdc++.h>
using namespace std;

long long countTriplets(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int n = A.size();
    long long count = 0;

    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            if (A[i] + A[j] + A[k] < K) {
                count += k - j;
                ++j;
            } else {
                --k;
            }
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        cout << countTriplets(A, K) << endl;
    }
    return 0;
}