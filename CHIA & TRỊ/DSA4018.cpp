#include <iostream>
using namespace std;

int countZero(int a[], int n) {
    int left = 0, right = n-1, res = n;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == 0) {
            left = mid + 1;
        } else {
            res = mid;
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int a[1005];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << countZero(a, n) << endl;
    }
    return 0;
}