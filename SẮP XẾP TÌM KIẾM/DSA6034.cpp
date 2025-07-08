#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long K;
        cin >> n >> K;

        long long A[n];
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        unordered_map<long long, int> freq;
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            long long need = K - A[i];
            if (freq.find(need) != freq.end()) {
                count += freq[need];
            }
            freq[A[i]]++;  // Cập nhật sau vì tránh đếm chính nó trong cặp
        }

        cout << count << endl;
    }
    return 0;
}
