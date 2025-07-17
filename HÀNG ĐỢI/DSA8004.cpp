#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int K;
        string S;
        cin >> K >> S;
        
        // Đếm tần suất xuất hiện của mỗi ký tự
        vector<int> freq(26, 0);
        for (char c : S) {
            freq[c - 'A']++;
        }
        
        // Sử dụng max heap để lưu trữ tần suất
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }
        
        // Loại bỏ K ký tự một cách tối ưu
        for (int i = 0; i < K; i++) {
            if (!pq.empty()) {
                int maxFreq = pq.top();
                pq.pop();
                
                if (maxFreq > 1) {
                    pq.push(maxFreq - 1);
                }
            }
        }
        
        // Tính giá trị của xâu sau khi loại bỏ
        long long result = 0;
        while (!pq.empty()) {
            int freq = pq.top();
            pq.pop();
            result += (long long)freq * freq;
        }
        
        cout << result << endl;
    }
    
    return 0;
} 