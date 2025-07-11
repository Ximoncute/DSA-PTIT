#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

// Hàm quay lui để tìm tổ hợp chập K
void backtrack(vector<int>& arr, vector<int>& current, int index, int k) {
    // Nếu đã chọn đủ K phần tử
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Nếu không đủ phần tử để chọn thì dừng
    if (index >= arr.size() || current.size() + (arr.size() - index) < k) {
        return;
    }
    
    // Thử chọn từng phần tử từ vị trí index trở đi
    for (int i = index; i < arr.size(); i++) {
        current.push_back(arr[i]);
        backtrack(arr, current, i + 1, k);
        current.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Sắp xếp mảng để đảm bảo thứ tự từ điển
        sort(arr.begin(), arr.end());
        
        result.clear();
        vector<int> current;
        
        // Gọi hàm quay lui
        backtrack(arr, current, 0, k);
        
        // In kết quả (đã được tạo theo thứ tự từ điển)
        for (const auto& combination : result) {
            for (int i = 0; i < combination.size(); i++) {
                if (i > 0) cout << " ";
                cout << combination[i];
            }
            cout << endl;
        }
    }
    
    return 0;
} 