#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string a, b;
        cin >> k >> a >> b;
        
        // Chuyển a, b về hệ 10
        long long num_a = 0, num_b = 0;
        long long base = 1;
        
        // Chuyển a
        for(int i = a.length() - 1; i >= 0; i--){
            num_a += (a[i] - '0') * base;
            base *= k;
        }
        
        // Chuyển b
        base = 1;
        for(int i = b.length() - 1; i >= 0; i--){
            num_b += (b[i] - '0') * base;
            base *= k;
        }
        
        // Tính tổng
        long long sum = num_a + num_b;
        
        // Chuyển về hệ k
        string result = "";
        if(sum == 0) result = "0";
        else{
            while(sum > 0){
                result = char('0' + sum % k) + result;
                sum /= k;
            }
        }
        
        cout << result << endl;
    }
    return 0;
} 