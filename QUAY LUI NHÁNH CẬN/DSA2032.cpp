#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> current;
vector<int> arr;
int target;

void backtrack(int start, int sum) {
    // Nếu tổng bằng target, thêm vào kết quả
    if (sum == target) {
        result.push_back(current);
        return;
    }
    
    // Nếu tổng vượt quá target, dừng
    if (sum > target) {
        return;
    }
    
    // Thử tất cả số từ vị trí start trở đi
    for (int i = start; i < arr.size(); i++) {
        current.push_back(arr[i]);
        // Gọi đệ quy với cùng chỉ số i vì có thể dùng lại số này
        backtrack(i, sum + arr[i]);
        current.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        arr.clear();
        arr.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Sắp xếp mảng để đảm bảo thứ tự không giảm
        sort(arr.begin(), arr.end());
        
        target = x;
        result.clear();
        current.clear();
        
        backtrack(0, 0);
        
        if (result.empty()) {
            cout << "-1" << endl;
        } else {
            cout << result.size();
            for (const auto& combination : result) {
                cout << " {";
                for (int i = 0; i < combination.size(); i++) {
                    if (i > 0) cout << " ";
                    cout << combination[i];
                }
                cout << "}";
            }
            cout << endl;
        }
    }
    
    return 0;
} 