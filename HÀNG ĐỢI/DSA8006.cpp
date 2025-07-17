#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

string findSmallest(int n) {
    if (n == 1) return "9";
    
    queue<pair<int, string>> q; // {remainder, number_string}
    vector<bool> visited(n, false);
    
    q.push({9 % n, "9"});
    visited[9 % n] = true;
    
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
        
        // Thêm '9' vào cuối
        int newRemainder9 = (remainder * 10 + 9) % n;
        if (!visited[newRemainder9]) {
            visited[newRemainder9] = true;
            q.push({newRemainder9, number + "9"});
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
        cout << findSmallest(N) << endl;
    }
    
    return 0;
} 