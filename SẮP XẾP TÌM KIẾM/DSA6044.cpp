#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), odd, even;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 == 1)
            odd.push_back(a[i]);
        else
            even.push_back(a[i]);
    }

    sort(odd.begin(), odd.end());           // Vị trí lẻ tăng dần
    sort(even.rbegin(), even.rend());       // Vị trí chẵn giảm dần

    int oi = 0, ei = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 1)
            cout << odd[oi++] << " ";
        else
            cout << even[ei++] << " ";
    }

    cout << '\n';
    return 0;
}
