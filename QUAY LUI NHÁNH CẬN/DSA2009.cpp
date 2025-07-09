#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int a[25];
int target;
bool used[25];

bool backtrack(int group, int currentSum, int start) {
    // Nếu đã chia đủ k nhóm
    if (group == k) {
        return true;
    }
    
    // Nếu nhóm hiện tại đã đủ tổng target
    if (currentSum == target) {
        return backtrack(group + 1, 0, 0);
    }
    
    // Thử các phần tử còn lại
    for (int i = start; i < n; i++) {
        if (!used[i] && currentSum + a[i] <= target) {
            used[i] = true;
            if (backtrack(group, currentSum + a[i], i + 1)) {
                return true;
            }
            used[i] = false;
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            used[i] = false;
        }
        
        // Kiểm tra điều kiện cơ bản
        if (sum % k != 0) {
            cout << 0 << endl;
            continue;
        }
        
        target = sum / k;
        
        // Sắp xếp giảm dần để tối ưu
        sort(a, a + n, greater<int>());
        
        // Kiểm tra xem có phần tử nào lớn hơn target không
        if (a[0] > target) {
            cout << 0 << endl;
            continue;
        }
        
        if (backtrack(0, 0, 0)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
} 