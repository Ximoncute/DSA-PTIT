#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generatePrimes() {
    vector<int> primes;
    for (int i = 1000; i <= 9999; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> getNeighbors(int num) {
    vector<int> neighbors;
    string s = to_string(num);
    
    for (int pos = 0; pos < 4; pos++) {
        char original = s[pos];
        
        for (char digit = '0'; digit <= '9'; digit++) {
            if (digit != original) {
                // Không được bắt đầu bằng 0
                if (pos == 0 && digit == '0') continue;
                
                s[pos] = digit;
                int newNum = stoi(s);
                
                if (isPrime(newNum)) {
                    neighbors.push_back(newNum);
                }
            }
        }
        s[pos] = original; // Khôi phục
    }
    
    return neighbors;
}

int minSteps(int S, int T) {
    if (S == T) return 0;
    
    queue<pair<int, int>> q; // {number, steps}
    unordered_set<int> visited;
    
    q.push({S, 0});
    visited.insert(S);
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        vector<int> neighbors = getNeighbors(current);
        
        for (int neighbor : neighbors) {
            if (neighbor == T) {
                return steps + 1;
            }
            
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, steps + 1});
            }
        }
    }
    
    return -1; // Không tìm thấy đường đi
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int S, target;
        cin >> S >> target;
        cout << minSteps(S, target) << endl;
    }
    
    return 0;
} 