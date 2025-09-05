#include <bits/stdc++.h>
using namespace std;

vector<int> fib;
set<vector<int>> result;

// Tạo dãy Fibonacci đến giá trị lớn hơn 870
void generateFibonacci() {
    int a = 0, b = 1;
    while (a <= 870) {
        fib.push_back(a);
        a += b;
        swap(a, b);
    }
}

// Kiểm tra xem tổng có trong dãy Fibonacci không
bool isFib(int sum) {
    return find(fib.begin(), fib.end(), sum) != fib.end();
}

// Hàm sinh tổ hợp chập K
void generateCombinations(int n, int k) {
    vector<bool> v(n);
    fill(v.begin() + k, v.end(), true);
    do {
        vector<int> comb;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) comb.push_back(i + 1);
        }
        int sum = 0;
        for (int x : comb) sum += x;
        if (isFib(sum)) {
            result.insert(comb);
        }
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    int N, K;
    cin >> N >> K;

    generateFibonacci();
    generateCombinations(N, K);

    for (const auto& comb : result) {
        for (int x : comb) cout << x << " ";
        cout << endl;
    }

    return 0;
}