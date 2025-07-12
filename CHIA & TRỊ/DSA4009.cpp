#include<iostream>
using namespace std;

const long long MOD = 1000000007;

void multiply(long long A[10][10], long long B[10][10], long long C[10][10], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
}

void power(long long A[10][10], long long result[10][10], int n, long long k){
    // Khởi tạo result là ma trận đơn vị
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = (i == j) ? 1 : 0;
        }
    }
    
    long long temp[10][10];
    // Copy A vào temp
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = A[i][j];
        }
    }
    
    while(k > 0){
        if(k % 2 == 1){
            long long newResult[10][10];
            multiply(result, temp, newResult, n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    result[i][j] = newResult[i][j];
                }
            }
        }
        
        long long newTemp[10][10];
        multiply(temp, temp, newTemp, n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = newTemp[i][j];
            }
        }
        
        k /= 2;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        
        long long A[10][10];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }
        
        long long result[10][10];
        power(A, result, n, k);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << result[i][j];
                if(j < n-1) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
} 