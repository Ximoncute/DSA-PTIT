#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& A, int N) {
    int totalSum = 0, leftSum = 0;

    for (int i = 0; i < N; ++i)
        totalSum += A[i];

    for (int i = 0; i < N; ++i) {
        totalSum -= A[i]; // totalSum giờ là tổng bên phải
        if (leftSum == totalSum)
            return i + 1; // chuyển sang chỉ số bắt đầu từ 1
        leftSum += A[i];
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        cout << findEquilibriumIndex(A, N) << '\n';
    }

    return 0;
}
