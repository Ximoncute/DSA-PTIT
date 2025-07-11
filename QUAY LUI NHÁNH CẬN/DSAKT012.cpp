#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

// Tạo tất cả tổng có thể từ một nửa mảng
void generateSums(vector<int>& arr, int start, int end, map<long long, int>& sums) {
    int size = end - start;
    
    // Duyệt tất cả tập con bằng bit manipulation
    for (int mask = 0; mask < (1 << size); mask++) {
        long long sum = 0;
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                sum += arr[start + i];
                count++;
            }
        }
        
        // Chỉ lưu tổng với số phần tử ít nhất
        if (sums.find(sum) == sums.end() || sums[sum] > count) {
            sums[sum] = count;
        }
    }
}

int main() {
    int n;
    long long S;
    cin >> n >> S;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Chia mảng thành 2 nửa
    int mid = n / 2;
    
    // Tạo tất cả tổng có thể từ 2 nửa
    map<long long, int> leftSums, rightSums;
    generateSums(arr, 0, mid, leftSums);
    generateSums(arr, mid, n, rightSums);
    
    int result = INT_MAX;
    
    // Kiểm tra từng tổng ở nửa trái
    for (map<long long, int>::iterator it = leftSums.begin(); it != leftSums.end(); it++) {
        long long need = S - it->first;
        
        // Tìm phần bù ở nửa phải
        if (rightSums.find(need) != rightSums.end()) {
            result = min(result, it->second + rightSums[need]);
        }
    }
    
    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
} 