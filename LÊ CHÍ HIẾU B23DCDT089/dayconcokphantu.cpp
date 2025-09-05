#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printCombinations(const vector<int>& A, int K, int start, vector<int>& comb) {
    if (comb.size() == K) {
        for (int i = 0; i < K; ++i) {
            cout << comb[i];
            if (i < K - 1) cout << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i < A.size(); ++i) {
        comb.push_back(A[i]);
        printCombinations(A, K, i + 1, comb);
        comb.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> comb;
    printCombinations(A, K, 0, comb);
    return 0;
}
