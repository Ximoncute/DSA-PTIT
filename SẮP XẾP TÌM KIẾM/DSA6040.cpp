#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N1, N2, N3;
        cin >> N1 >> N2 >> N3;
        vector<long long> A(N1), B(N2), C(N3);
        for (long long i = 0; i < N1; ++i) cin >> A[i];
        for (long long i = 0; i < N2; ++i) cin >> B[i];
        for (long long i = 0; i < N3; ++i) cin >> C[i];

        vector<long long> result;
        long long i = 0, j = 0, k = 0;

        long long last = -1;

        while (i < N1 && j < N2 && k < N3) {
            if (A[i] == B[j] && B[j] == C[k]) {
                if (result.empty() || result.back() != A[i]) // tránh trùng
                    result.push_back(A[i]);
                ++i; ++j; ++k;
            } else {
                long long mn = min({A[i], B[j], C[k]});
                if (A[i] == mn) ++i;
                else if (B[j] == mn) ++j;
                else ++k;
            }
        }

        if (result.empty()) cout << "-1\n";
        else {
            for (long long x : result) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
