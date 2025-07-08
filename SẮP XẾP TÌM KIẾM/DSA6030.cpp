#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> steps; // Lưu các bước

        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            steps.push_back(a);
        }

        // In các bước theo thứ tự ngược
        for (int i = steps.size() - 1; i >= 0; i--) {
            cout << "Buoc " << i + 1 << ": ";
            for (int x : steps[i]) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
