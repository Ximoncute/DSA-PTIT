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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int k = 0;
        // Tìm vị trí i mà a[i-1] > a[i]
        for (int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                k = i;
                break;
            }
        }
        
        cout << k << endl;
    }
    return 0;
} 