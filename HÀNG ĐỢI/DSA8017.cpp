#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    // Sắp xếp theo độ dài giảm dần, nếu cùng độ dài thì theo thứ tự giảm dần
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a > b;
}

void generateLuckyNumbers(int n, vector<string>& result) {
    // Sinh các số lộc phát từ 1 chữ số đến n chữ số
    for (int len = 1; len <= n; len++) {
        // Sinh tất cả các số có độ dài len
        int totalNumbers = 1 << len; // 2^len
        
        for (int i = 0; i < totalNumbers; i++) {
            string number = "";
            for (int j = len - 1; j >= 0; j--) {
                if ((i >> j) & 1) {
                    number += "8";
                } else {
                    number += "6";
                }
            }
            result.push_back(number);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<string> luckyNumbers;
        generateLuckyNumbers(N, luckyNumbers);
        
        // Sắp xếp theo thứ tự giảm dần (số lớn trước, độ dài dài trước)
        sort(luckyNumbers.begin(), luckyNumbers.end(), compare);
        
        // In kết quả
        for (int i = 0; i < luckyNumbers.size(); i++) {
            cout << luckyNumbers[i];
            if (i < luckyNumbers.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
} 