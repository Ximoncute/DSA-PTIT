#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k >> s;
        
        // Đếm tần suất xuất hiện của mỗi ký tự
        map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        
        // Tạo max-heap với tần suất
        priority_queue<int> maxHeap;
        for(auto& p : freq){
            maxHeap.push(p.second);
        }
        
        // Thực hiện K lần loại bỏ ký tự
        for(int i = 0; i < k; i++){
            if(!maxHeap.empty()){
                int maxFreq = maxHeap.top();
                maxHeap.pop();
                
                // Giảm tần suất đi 1
                if(maxFreq > 1){
                    maxHeap.push(maxFreq - 1);
                }
            }
        }
        
        // Tính giá trị cuối cùng (tổng bình phương các tần suất)
        long long result = 0;
        while(!maxHeap.empty()){
            int freq = maxHeap.top();
            maxHeap.pop();
            result += (long long)freq * freq;
        }
        
        cout << result << endl;
    }
    return 0;
} 