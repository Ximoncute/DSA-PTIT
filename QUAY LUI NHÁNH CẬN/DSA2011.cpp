#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int n, S;
vector<int> t;
map<int, int> left_sums, right_sums;

void generate_sums(int start, int end, int sum, int count, map<int, int>& sums) {
    if (start > end) {
        if (sums.find(sum) == sums.end() || sums[sum] > count) {
            sums[sum] = count;
        }
        return;
    }
    
    // Không chọn phần tử hiện tại
    generate_sums(start + 1, end, sum, count, sums);
    
    // Chọn phần tử hiện tại
    generate_sums(start + 1, end, sum + t[start], count + 1, sums);
}

int solve() {
    int mid = n / 2;
    
    left_sums.clear();
    right_sums.clear();
    
    // Sinh tất cả tổng có thể từ nửa trái
    generate_sums(0, mid - 1, 0, 0, left_sums);
    
    // Sinh tất cả tổng có thể từ nửa phải
    generate_sums(mid, n - 1, 0, 0, right_sums);
    
    int result = 1e9;
    
    // Với mỗi tổng từ nửa trái, tìm tổng tương ứng từ nửa phải
    for (auto& p : left_sums) {
        int left_sum = p.first;
        int left_count = p.second;
        int need = S - left_sum;
        
        if (right_sums.find(need) != right_sums.end()) {
            result = min(result, left_count + right_sums[need]);
        }
    }
    
    return result == 1e9 ? -1 : result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> n >> S;
        
        t.clear();
        t.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        
        cout << solve() << endl;
    }
    
    return 0;
} 