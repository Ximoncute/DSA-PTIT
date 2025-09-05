#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate all subsequences with odd sum
void generateSubsequences(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == arr.size()) {
        if (!current.empty()) {
            int sum = 0;
            for (int num : current) {
                sum += num;
            }
            if (sum % 2 != 0) {
                result.push_back(current);
            }
        }
        return;
    }
    
    // Include current element
    current.push_back(arr[index]);
    generateSubsequences(arr, index + 1, current, result);
    
    // Exclude current element
    current.pop_back();
    generateSubsequences(arr, index + 1, current, result);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Sort in decreasing order
        sort(arr.rbegin(), arr.rend());
        
        vector<vector<int>> subsequences;
        vector<int> current;
        
        // Generate all subsequences with odd sum
        generateSubsequences(arr, 0, current, subsequences);
        
        // Sort subsequences lexicographically
        sort(subsequences.begin(), subsequences.end());
        
        // Output the results
        for (const auto& subseq : subsequences) {
            for (int i = 0; i < subseq.size(); i++) {
                cout << subseq[i];
                if (i < subseq.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
