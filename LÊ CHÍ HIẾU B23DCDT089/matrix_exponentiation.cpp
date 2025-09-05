#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

// Matrix multiplication
vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    
    return result;
}

// Matrix exponentiation using binary exponentiation
vector<vector<long long>> matrixPower(vector<vector<long long>> matrix, long long power) {
    int n = matrix.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    
    // Initialize result as identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    
    while (power > 0) {
        if (power & 1) {
            result = multiply(result, matrix);
        }
        matrix = multiply(matrix, matrix);
        power >>= 1;
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        
        vector<vector<long long>> matrix(N, vector<long long>(N));
        
        // Read matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        
        // Compute A^K
        vector<vector<long long>> result = matrixPower(matrix, K);
        
        // Sum first row elements
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            sum = (sum + result[0][j]) % MOD;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
