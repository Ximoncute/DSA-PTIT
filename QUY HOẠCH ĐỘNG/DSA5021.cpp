#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        
        // Sort by ending time (second element)
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int count = 0;
        int last_end = -1;
        
        for (int i = 0; i < n; i++) {
            // If current pair's start is greater than last selected pair's end
            if (pairs[i].first > last_end) {
                count++;
                last_end = pairs[i].second;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
} 