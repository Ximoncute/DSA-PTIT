#include <iostream>
using namespace std;

// Simple big integer using arrays
struct BigInt {
    int digits[500];  // Should be enough for Catalan numbers up to n=100
    int size;
    
    BigInt(int n = 0) {
        size = 0;
        if (n == 0) {
            digits[0] = 0;
            size = 1;
        } else {
            while (n > 0) {
                digits[size++] = n % 10;
                n /= 10;
            }
        }
    }
    
    BigInt add(const BigInt& other) const {
        BigInt result;
        result.size = 0;
        
        int carry = 0;
        int i = 0;
        int maxSize = (size > other.size) ? size : other.size;
        
        while (i < maxSize || carry) {
            int sum = carry;
            if (i < size) sum += digits[i];
            if (i < other.size) sum += other.digits[i];
            
            result.digits[result.size++] = sum % 10;
            carry = sum / 10;
            i++;
        }
        
        return result;
    }
    
    BigInt multiply(const BigInt& other) const {
        BigInt result;
        for (int i = 0; i < 500; i++) result.digits[i] = 0;
        result.size = size + other.size;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                result.digits[i + j] += digits[i] * other.digits[j];
                if (result.digits[i + j] >= 10) {
                    result.digits[i + j + 1] += result.digits[i + j] / 10;
                    result.digits[i + j] %= 10;
                }
            }
        }
        
        // Remove leading zeros
        while (result.size > 1 && result.digits[result.size - 1] == 0) {
            result.size--;
        }
        
        return result;
    }
    
    void print() const {
        for (int i = size - 1; i >= 0; i--) {
            cout << digits[i];
        }
    }
};

BigInt catalan(int n) {
    if (n <= 1) return BigInt(1);
    
    BigInt dp[101];
    dp[0] = BigInt(1);
    dp[1] = BigInt(1);
    
    for (int i = 2; i <= n; i++) {
        dp[i] = BigInt(0);
        for (int j = 0; j < i; j++) {
            BigInt temp = dp[j].multiply(dp[i-1-j]);
            dp[i] = dp[i].add(temp);
        }
    }
    
    return dp[n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        BigInt result = catalan(n);
        result.print();
        cout << endl;
    }
    
    return 0;
} 