#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int n, S;
vector<int> t;

void generate(int start, int end, int sum, int count, map<int, int>& sums) {
    if (start > end) {
        if (sums.find(sum) == sums.end() || sums[sum] > count) {
            sums[sum] = count;
        }
        return;
    }
    
    // Không chọn
    generate(start + 1, end, sum, count, sums);
    
    // Chọn
    if (sum <= S) { // Pruning: không vượt quá S
        generate(start + 1, end, sum + t[start], count + 1, sums);
    }
}

int solve() {
    int mid = n / 2;
    map<int, int> left_sums, right_sums;
    
    // Sinh tổng từ nửa trái [0, mid-1]
    generate(0, mid - 1, 0, 0, left_sums);
    
    // Sinh tổng từ nửa phải [mid, n-1]  
    generate(mid, n - 1, 0, 0, right_sums);
    
    int result = 1e9;
    
    // Kết hợp 2 nửa
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
    cin >> n >> S;
    
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    cout << solve() << endl;
    
    return 0;
} 