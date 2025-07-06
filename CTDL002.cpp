#include <iostream>
using namespace std;

int n, K, A[20], cnt = 0;
int B[20];

void Try(int i, int sum, int pos) {
    if (sum == K) {
        for (int j = 0; j < pos; ++j) {
            cout << B[j];
            if (j < pos - 1) cout << " ";
        }
        cout << endl;
        cnt++;
        return;
    }
    if (i == n || sum > K) return;
    // Không chọn A[i]
    Try(i + 1, sum, pos);
    // Chọn A[i]
    B[pos] = A[i];
    Try(i + 1, sum + A[i], pos + 1);
}

int main() {
    cin >> n >> K;
    for (int i = 0; i < n; ++i) cin >> A[i];
    Try(0, 0, 0);
    cout << cnt << endl;
    return 0;
}