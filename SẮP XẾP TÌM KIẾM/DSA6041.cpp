#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Tăng tốc độ đọc ghi
    cin.tie(nullptr); // Không flush sau mỗi lần cout

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        // Boyer-Moore Majority Vote Algorithm
        int candidate = A[0], count = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] == candidate) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    candidate = A[i];
                    count = 1;
                }
            }
        }

        // Kiểm tra lại candidate có đúng là majority không
        count = 0;
        for (int i = 0; i < N; ++i)
            if (A[i] == candidate)
                ++count;

        if (count > N / 2)
            cout << candidate << '\n';
        else
            cout << "NO\n";
    }

    return 0;
}