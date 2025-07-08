#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long K;
        cin >> n >> K;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        long long count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                long long sum = a[i] + a[left] + a[right];
                if (sum < K) {
                    count += (right - left); // Các bộ ba (i, left, left+1 ... right-1)
                    ++left;
                } else {
                    --right;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}
