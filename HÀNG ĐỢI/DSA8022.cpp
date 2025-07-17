#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string findLargestDivisibleBy3(vector<int>& digits) {
    int n = digits.size();
    
    // Tính tổng tất cả các chữ số
    int totalSum = 0;
    for (int digit : digits) {
        totalSum += digit;
    }
    
    // Sắp xếp giảm dần để tạo số lớn nhất
    sort(digits.begin(), digits.end(), greater<int>());
    
    // Nếu tổng chia hết cho 3, sử dụng tất cả chữ số
    if (totalSum % 3 == 0) {
        // Trường hợp đặc biệt: tất cả chữ số là 0
        if (digits[0] == 0) return "0";
        
        string result = "";
        for (int digit : digits) {
            result += to_string(digit);
        }
        return result;
    }
    
    // Nếu tổng % 3 == 1, cần loại bỏ chữ số nhỏ nhất có remainder = 1
    // hoặc 2 chữ số nhỏ nhất có remainder = 2
    if (totalSum % 3 == 1) {
        // Tìm chữ số nhỏ nhất có remainder = 1
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] % 3 == 1) {
                digits.erase(digits.begin() + i);
                break;
            }
        }
        // Nếu không tìm thấy, loại bỏ 2 chữ số nhỏ nhất có remainder = 2
        if (digits.size() == n) {
            int count = 0;
            for (int i = n - 1; i >= 0 && count < 2; i--) {
                if (digits[i] % 3 == 2) {
                    digits.erase(digits.begin() + i);
                    count++;
                }
            }
        }
    }
    
    // Nếu tổng % 3 == 2, cần loại bỏ chữ số nhỏ nhất có remainder = 2
    // hoặc 2 chữ số nhỏ nhất có remainder = 1
    if (totalSum % 3 == 2) {
        // Tìm chữ số nhỏ nhất có remainder = 2
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] % 3 == 2) {
                digits.erase(digits.begin() + i);
                break;
            }
        }
        // Nếu không tìm thấy, loại bỏ 2 chữ số nhỏ nhất có remainder = 1
        if (digits.size() == n) {
            int count = 0;
            for (int i = n - 1; i >= 0 && count < 2; i--) {
                if (digits[i] % 3 == 1) {
                    digits.erase(digits.begin() + i);
                    count++;
                }
            }
        }
    }
    
    // Nếu không còn chữ số nào, trả về -1
    if (digits.empty()) return "-1";
    
    // Trường hợp đặc biệt: tất cả chữ số còn lại là 0
    if (digits[0] == 0) return "0";
    
    // Tạo kết quả
    string result = "";
    for (int digit : digits) {
        result += to_string(digit);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> digits(N);
        for (int i = 0; i < N; i++) {
            cin >> digits[i];
        }
        
        cout << findLargestDivisibleBy3(digits) << endl;
    }
    
    return 0;
} 