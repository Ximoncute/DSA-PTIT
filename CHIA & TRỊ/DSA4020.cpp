#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int k) {
    int left = 0, right = n-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == k) return mid + 1; // vị trí bắt đầu từ 1
        else if(a[mid] < k) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int res = binarySearch(a, n, k);
        if(res == -1) cout << "NO" << endl;
        else cout << res << endl;
    }
    return 0;
}