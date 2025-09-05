#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[20];
int combination[20];

void printCombination() {
    for (int i = 0; i < K; i++) {
        cout << combination[i] << " ";
    }
    cout << endl;
}

void generateCombinations(int start, int depth) {
    if (depth == K) {
        printCombination();
        return;
    }
    
    for (int i = start; i < N; i++) {
        combination[depth] = A[i];
        generateCombinations(i + 1, depth + 1);
    }
}

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the array to ensure combinations are in lexicographical order
    sort(A, A + N);
    
    generateCombinations(0, 0);
    
    return 0;
}
