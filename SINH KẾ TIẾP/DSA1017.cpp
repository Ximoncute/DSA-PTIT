#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string binary;
        cin >> binary;
        
        string gray = "";
        
        // Bit đầu tiên của Gray = bit đầu tiên của Binary
        gray += binary[0];
        
        // Các bit tiếp theo: gray[i] = binary[i-1] XOR binary[i]
        for (int i = 1; i < binary.length(); i++) {
            if (binary[i-1] == binary[i]) {
                gray += "0";  // giống nhau thì XOR = 0
            } else {
                gray += "1";  // khác nhau thì XOR = 1
            }
        }
        
        cout << gray << endl;
    }
    
    return 0;
} 