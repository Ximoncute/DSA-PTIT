#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long maxValue = LLONG_MIN;
    
    // Tối ưu hóa: f(i,j) + g(i,j) = (|a[i]| + |a[i+1]| + ... + |a[j]|) + (a[i] + a[i+1] + ... + a[j])
    // = (|a[i]| + a[i]) + (|a[i+1]| + a[i+1]) + ... + (|a[j]| + a[j])
    // Với mỗi phần tử a[k], ta có |a[k]| + a[k] = 2*a[k] nếu a[k] >= 0, = 0 nếu a[k] < 0
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = abs(a[i]) + a[i];
    }
    
    // Bây giờ bài toán trở thành tìm maximum subarray sum của mảng b
    // Sử dụng thuật toán Kadane
    long long currentSum = 0;
    maxValue = b[0];
    
    for (int i = 0; i < n; i++) {
        currentSum = max(b[i], currentSum + b[i]);
        maxValue = max(maxValue, currentSum);
    }
    
    cout << maxValue << endl;
    
    return 0;
} 