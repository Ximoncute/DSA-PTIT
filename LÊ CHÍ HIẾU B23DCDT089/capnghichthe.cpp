#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;
    
public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, long long delta) {
        idx++;
        while (idx <= size) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }
    
    long long query(int idx) {
        idx++;
        long long res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

long long countInversions(vector<long long>& arr) {
    int n = arr.size();

    vector<pair<long long, int>> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = {arr[i], i};
    }
    

    sort(temp.begin(), temp.end());

    vector<long long> compressed(n);
    long long rank = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && temp[i].first != temp[i-1].first) {
            rank++;
        }
        compressed[temp[i].second] = rank;
    }
    
    FenwickTree ft(n);
    long long inversions = 0;
    

    for (int i = n - 1; i >= 0; i--) {
        inversions += ft.query(compressed[i] - 1);
        ft.update(compressed[i], 1);
    }
    
    return inversions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        cout << countInversions(A) << endl;
    }
    
    return 0;
}
