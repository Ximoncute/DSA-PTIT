#include <iostream>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumBitonicSubsequence(int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    
    // lis[i] stores the maximum sum of increasing subsequence ending at index i
    int lis[100];
    
    // lds[i] stores the maximum sum of decreasing subsequence starting at index i
    int lds[100];
    
    // Initialize lis array - each element is at least its own value
    for (int i = 0; i < n; i++) {
        lis[i] = arr[i];
    }
    
    // Fill lis array (left to right)
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis[i] = max_of_two(lis[i], lis[j] + arr[i]);
            }
        }
    }
    
    // Initialize lds array - each element is at least its own value
    for (int i = 0; i < n; i++) {
        lds[i] = arr[i];
    }
    
    // Fill lds array (right to left)
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                lds[i] = max_of_two(lds[i], lds[j] + arr[i]);
            }
        }
    }
    
    // Find maximum sum bitonic subsequence
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        // Bitonic sum through position i is lis[i] + lds[i] - arr[i]
        // (subtract arr[i] because it's counted in both lis[i] and lds[i])
        int bitonicSum = lis[i] + lds[i] - arr[i];
        maxSum = max_of_two(maxSum, bitonicSum);
    }
    
    return maxSum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int arr[100];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int result = maxSumBitonicSubsequence(arr, N);
        cout << result << endl;
    }
    
    return 0;
} 