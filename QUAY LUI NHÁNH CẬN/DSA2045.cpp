#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> result;

// Hàm quay lui để tạo tất cả tập con
void backtrack(string& s, string current, int index) {
    // Thêm tập con hiện tại vào kết quả (bao gồm cả tập rỗng)
    if (!current.empty()) {
        result.push_back(current);
    }
    
    // Thử thêm từng ký tự từ vị trí index trở đi
    for (int i = index; i < s.length(); i++) {
        // Thêm ký tự s[i] vào tập con hiện tại
        backtrack(s, current + s[i], i + 1);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        // Sắp xếp xâu để đảm bảo thứ tự từ điển
        sort(s.begin(), s.end());
        
        result.clear();
        
        // Gọi hàm quay lui
        backtrack(s, "", 0);
        
        // Sắp xếp kết quả theo thứ tự từ điển
        sort(result.begin(), result.end());
        
        // In kết quả
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
} 