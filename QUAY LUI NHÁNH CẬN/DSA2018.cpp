#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính toán biểu thức [[[A op1 B] op2 C] op3 D] op4 E
int calculate(vector<int>& nums, vector<char>& ops) {
    int result = nums[0];
    
    for (int i = 0; i < 4; i++) {
        if (ops[i] == '+') {
            result += nums[i + 1];
        } else if (ops[i] == '-') {
            result -= nums[i + 1];
        } else if (ops[i] == '*') {
            result *= nums[i + 1];
        }
    }
    
    return result;
}

// Hàm sinh tất cả tổ hợp phép toán
void generateOperators(vector<char>& ops, int pos, vector<int>& nums, bool& found) {
    if (found) return;
    
    if (pos == 4) {
        if (calculate(nums, ops) == 23) {
            found = true;
        }
        return;
    }
    
    vector<char> operators = {'+', '-', '*'};
    for (char op : operators) {
        ops[pos] = op;
        generateOperators(ops, pos + 1, nums, found);
        if (found) return;
    }
}

// Hàm kiểm tra một hoán vị
bool checkPermutation(vector<int>& nums) {
    vector<char> ops(4);
    bool found = false;
    generateOperators(ops, 0, nums, found);
    return found;
}

// Hàm chính để giải bài toán
bool solve(vector<int>& nums) {
    // Sinh tất cả hoán vị của 5 số
    sort(nums.begin(), nums.end());
    
    do {
        if (checkPermutation(nums)) {
            return true;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        vector<int> nums(5);
        for (int i = 0; i < 5; i++) {
            cin >> nums[i];
        }
        
        if (solve(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
} 