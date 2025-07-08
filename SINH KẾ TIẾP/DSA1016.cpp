#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> results;

// Hàm đệ quy phân tích số n thành tổng
// current: mảng hiện tại đang xây dựng
// n: số còn lại cần phân tích
// max_val: giá trị lớn nhất có thể dùng (để tránh trùng lặp)
void phanTich(vector<int>& current, int n, int max_val) {
    // Trường hợp cơ sở: n = 0 nghĩa là đã tìm được 1 cách phân tích
    if (n == 0) {
        results.push_back(current);
        return;
    }
    
    // Thử tất cả các giá trị từ min(n, max_val) xuống 1
    for (int i = min(n, max_val); i >= 1; i--) {
        current.push_back(i);      // Thêm i vào mảng hiện tại
        phanTich(current, n - i, i); // Đệ quy với n-i và max_val = i
        current.pop_back();        // Backtrack
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        results.clear(); // Xóa kết quả cũ
        vector<int> current;
        
        phanTich(current, n, n);
        
        // In kết quả
        for (int i = 0; i < results.size(); i++) {
            cout << "(";
            for (int j = 0; j < results[i].size(); j++) {
                cout << results[i][j];
                if (j < results[i].size() - 1) cout << " ";
            }
            cout << ")";
            if (i < results.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 