#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int groups = 1;
    int last = A[0];
    
    for (int i = 1; i < N; ++i) {
        if (A[i] - last > K) {
            groups++;
            last = A[i];
        }
    }
    
    cout << groups << '\n';
    return 0;
}
