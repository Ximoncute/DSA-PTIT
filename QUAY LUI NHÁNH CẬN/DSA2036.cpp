#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Vector lưu kết quả các dãy con
vector<vector<int>> result;

// Hàm quay lui để tìm các dãy con
void backtrack(vector<int>& arr, vector<int>& current, int index) {
    // Kiểm tra dãy con hiện tại có tổng nguyên tố không
    if (!current.empty()) {
        int sum = 0;
        for (int x : current) {
            sum += x;
        }
        if (isPrime(sum)) {
            // Tạo bản sao và sắp xếp giảm dần
            vector<int> temp = current;
            sort(temp.rbegin(), temp.rend());
            result.push_back(temp);
        }
    }
    
    // Thử thêm các phần tử tiếp theo
    for (int i = index; i < arr.size(); i++) {
        current.push_back(arr[i]);
        backtrack(arr, current, i + 1);
        current.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Sắp xếp mảng để đảm bảo thứ tự từ điển
        sort(arr.begin(), arr.end());
        
        result.clear();
        vector<int> current;
        
        // Gọi hàm quay lui
        backtrack(arr, current, 0);
        
        // Sắp xếp kết quả theo thứ tự từ điển
        sort(result.begin(), result.end());
        
        // In kết quả
        for (const auto& subsequence : result) {
            for (int i = 0; i < subsequence.size(); i++) {
                if (i > 0) cout << " ";
                cout << subsequence[i];
            }
            cout << endl;
        }
    }
    
    return 0;
} 