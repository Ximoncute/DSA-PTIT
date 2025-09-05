#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline bool isFourDigit(int x) {
    return x >= 1000 && x <= 9999;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        a.reserve(n);
        
        // Chỉ nhận các số có đúng 4 chữ số
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (isFourDigit(x)) {
                a.push_back(x);
            }
        }
        
        sort(a.begin(), a.end());
        
        if (!a.empty()) {
            cout << a[0];
            for (int i = 1; i < a.size(); i++) {
                cout << ' ' << a[i];
            }
        }
        cout << '\n';
    }
    return 0;
}