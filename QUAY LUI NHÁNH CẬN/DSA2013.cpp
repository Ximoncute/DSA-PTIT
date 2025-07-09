#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Tạo danh sách số nguyên tố lớn hơn P và nhỏ hơn S
vector<int> generatePrimes(int P, int maxVal) {
    vector<int> primes;
    for (int i = P + 1; i <= maxVal; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Hàm quay lui để tìm tổ hợp
void backtrack(vector<int>& primes, vector<int>& current, vector<vector<int>>& results, 
               int start, int remaining, int count, int targetCount) {
    // Nếu đã chọn đủ số và tổng bằng 0
    if (count == targetCount && remaining == 0) {
        results.push_back(current);
        return;
    }
    
    // Nếu đã chọn đủ số hoặc tổng âm hoặc không còn số để chọn
    if (count == targetCount || remaining <= 0 || start >= primes.size()) {
        return;
    }
    
    // Thử từng số nguyên tố từ vị trí start
    for (int i = start; i < primes.size(); i++) {
        if (primes[i] <= remaining) {
            current.push_back(primes[i]);
            backtrack(primes, current, results, i + 1, remaining - primes[i], count + 1, targetCount);
            current.pop_back();
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, P, S;
        cin >> N >> P >> S;
        
        // Tạo danh sách số nguyên tố lớn hơn P
        vector<int> primes = generatePrimes(P, S);
        
        vector<vector<int>> results;
        vector<int> current;
        
        // Tìm tất cả tổ hợp
        backtrack(primes, current, results, 0, S, 0, N);
        
        // Sắp xếp kết quả theo thứ tự từ điển
        sort(results.begin(), results.end());
        
        // In kết quả
        cout << results.size() << endl;
        for (const auto& result : results) {
            for (int i = 0; i < result.size(); i++) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }
    
    return 0;
} 