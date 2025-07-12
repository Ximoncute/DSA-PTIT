#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm kiểm tra xem một số có phải là khối lập phương không
bool isPerfectCube(long long n) {
    if (n <= 0) return false;
    long long cubeRoot = round(cbrt(n));
    return cubeRoot * cubeRoot * cubeRoot == n;
}

// Hàm tìm số khối lập phương lớn nhất
long long findMaxCube(string s) {
    long long maxCube = -1;
    int n = s.length();
    
    // Tạo tất cả các số có thể bằng bitmask
    for (int mask = 1; mask < (1 << n); mask++) {
        string num = "";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                num += s[i];
            }
        }
        
        // Bỏ qua số bắt đầu bằng 0 (trừ "0")
        if (num.length() > 1 && num[0] == '0') {
            continue;
        }
        
        try {
            long long val = stoll(num);
            if (isPerfectCube(val)) {
                maxCube = max(maxCube, val);
            }
        } catch (...) {
            continue;
        }
    }
    
    return maxCube;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string n;
        cin >> n;
        
        // Với số quá lớn, ta cần tối ưu hóa
        if (n.length() > 18) {
            // Với chuỗi quá dài, ta chỉ xét các khối lập phương có thể
            // Tạo danh sách các khối lập phương có thể
            vector<long long> cubes;
            for (long long i = 1; i * i * i <= 1000000000000000000LL; i++) {
                cubes.push_back(i * i * i);
            }
            
            long long maxCube = -1;
            
            // Kiểm tra xem có thể tạo được khối lập phương nào không
            for (long long cube : cubes) {
                string cubeStr = to_string(cube);
                
                // Kiểm tra xem cubeStr có phải là subsequence của n không
                int j = 0;
                for (int i = 0; i < n.length() && j < cubeStr.length(); i++) {
                    if (n[i] == cubeStr[j]) {
                        j++;
                    }
                }
                
                if (j == cubeStr.length()) {
                    maxCube = max(maxCube, cube);
                }
            }
            
            cout << maxCube << endl;
        } else {
            cout << findMaxCube(n) << endl;
        }
    }
    
    return 0;
} 