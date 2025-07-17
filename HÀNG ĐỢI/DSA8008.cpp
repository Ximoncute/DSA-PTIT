#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

string findSmallestBDN(int n) {
    if (n == 1) return "1";
    
    queue<pair<int, string>> q; // {remainder, number_string}
    vector<bool> visited(n, false);
    
    q.push({1 % n, "1"});
    visited[1 % n] = true;
    
    while (!q.empty()) {
        int remainder = q.front().first;
        string number = q.front().second;
        q.pop();
        
        if (remainder == 0) {
            return number;
        }
        
        // Thêm '0' vào cuối
        int newRemainder0 = (remainder * 10) % n;
        if (!visited[newRemainder0]) {
            visited[newRemainder0] = true;
            q.push({newRemainder0, number + "0"});
        }
        
        // Thêm '1' vào cuối
        int newRemainder1 = (remainder * 10 + 1) % n;
        if (!visited[newRemainder1]) {
            visited[newRemainder1] = true;
            q.push({newRemainder1, number + "1"});
        }
    }
    
    return ""; // Không tìm thấy (trường hợp này không xảy ra)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        cout << findSmallestBDN(N) << endl;
    }
    
    return 0;
} 