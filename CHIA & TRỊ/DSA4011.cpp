#include<iostream>
#include<string>
using namespace std;

long long binaryToDecimal(string binary){
    long long decimal = 0;
    long long base = 1;
    
    for(int i = binary.length() - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += base;
        }
        base *= 2;
    }
    
    return decimal;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        
        long long num1 = binaryToDecimal(s1);
        long long num2 = binaryToDecimal(s2);
        
        long long result = num1 * num2;
        
        cout << result << endl;
    }
    return 0;
} 