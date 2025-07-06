#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}