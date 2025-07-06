#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> tg;
        tg.push_back(a);
        for (int i = 1; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < tg[i-1].size() - 1; j++) {
                tmp.push_back(tg[i-1][j] + tg[i-1][j+1]);
            }
            tg.push_back(tmp);
        }
        for (int i = 0; i < tg.size(); i++) {
            cout << "[";
            for (int j = 0; j < tg[i].size(); j++) {
                cout << tg[i][j];
                if (j != tg[i].size() - 1) cout << " ";
            }
            cout << "]\n";
        }
    }
    return 0;
}