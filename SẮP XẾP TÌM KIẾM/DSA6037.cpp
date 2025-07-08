#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> maxLeft(n), minRight(n);
        
        // Tính max từ trái
        maxLeft[0] = a[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], a[i]);
        }
        
        // Tính min từ phải  
        minRight[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            minRight[i] = min(minRight[i+1], a[i]);
        }
        
        vector<int> res;
        for (int i = 0; i < n-1; i++) {
            if (maxLeft[i] <= minRight[i+1]) {
                res.push_back(i+1);
            }
        }
        
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size()-1) cout << " ";
        }
        if (res.size() > 0) cout << endl;
    }
    return 0;
} 