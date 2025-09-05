#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        long long prev1 = 0, prev2 = 0;
        for (int i = 0; i < N; ++i) {
            long long curr = max(prev1, prev2 + A[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        cout << prev1 << endl;
    }
    return 0;
}