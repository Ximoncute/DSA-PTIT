#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

// Hàm quay lui để phân tích số n
void backtrack(int n, vector<int>& current, int max_val) {
    // Nếu n = 0, ta đã tìm được một cách phân tích
    if (n == 0) {
        result.push_back(current);
        return;
    }
    
    // Thử từ max_val xuống 1 (để đảm bảo thứ tự giảm dần)
    for (int i = min(max_val, n); i >= 1; i--) {
        current.push_back(i);
        backtrack(n - i, current, i); // max_val = i để tránh trùng lặp
        current.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        result.clear();
        vector<int> current;
        
        // Gọi hàm quay lui
        backtrack(n, current, n);
        
        // In số lượng cách phân tích
        cout << result.size() << endl;
        
        // In các cách phân tích
        for (const auto& partition : result) {
            cout << "(";
            for (int i = 0; i < partition.size(); i++) {
                if (i > 0) cout << " ";
                cout << partition[i];
            }
            cout << ")";
            if (&partition != &result.back()) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 