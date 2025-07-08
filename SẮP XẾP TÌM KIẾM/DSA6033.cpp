#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<int> LMin(n), RMax(n);
        LMin[0] = A[0];
        for (int i = 1; i < n; i++)
            LMin[i] = min(A[i], LMin[i - 1]);

        RMax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            RMax[i] = max(A[i], RMax[i + 1]);

        int i = 0, j = 0, maxDiff = -1;
        while (i < n && j < n) {
            if (LMin[i] < RMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j++;
            } else {
                i++;
            }
        }

        cout << maxDiff << endl;
    }
    return 0;
}
