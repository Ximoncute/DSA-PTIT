#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm quay lui để tìm các dãy con có tổng là số nguyên tố
void backtrack(vector<int>& A, vector<int>& current, int index, vector<vector<int>>& result) {
    if (!current.empty()) {
        int sum = 0;
        for (int num : current) sum += num;
        if (isPrime(sum)) {
            result.push_back(current);
        }
    }
    for (int i = index; i < A.size(); ++i) {
        current.push_back(A[i]);
        backtrack(A, current, i + 1, result);
        current.pop_back();
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        sort(A.begin(), A.end()); // Sắp xếp để đảm bảo thứ tự từ điển
        vector<vector<int>> result;
        vector<int> current;
        backtrack(A, current, 0, result);
        sort(result.begin(), result.end()); // Sắp xếp kết quả theo thứ tự từ điển
        for (const auto& subset : result) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}