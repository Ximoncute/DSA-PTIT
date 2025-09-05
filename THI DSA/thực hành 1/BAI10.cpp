#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> names(N);
    for (int i = 0; i < N; ++i) cin >> names[i];
    vector<int> cnt(101, 0); // Độ dài tên tối đa 100
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        int len = names[i].size();
        res += cnt[len];
        cnt[len]++;
        if (i >= K) {
            int old_len = names[i - K].size();
            cnt[old_len]--;
        }
    }
    cout << res << endl;
    return 0;
}