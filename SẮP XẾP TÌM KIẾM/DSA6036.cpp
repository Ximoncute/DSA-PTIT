#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasTripletSum(vector<int>& A, int N, int K) {
    sort(A.begin(), A.end());

    for (int i = 0; i < N - 2; ++i) {
        int l = i + 1, r = N - 1;

        while (l < r) {
            long long sum = 1LL * A[i] + A[l] + A[r];
            if (sum == K) return true;
            else if (sum < K) l++;
            else r--;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        if (hasTripletSum(A, N, K)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
