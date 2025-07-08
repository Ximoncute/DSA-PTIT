#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string gray;
        cin >> gray;
        
        string binary = "";
        
        // Bit đầu tiên của binary = bit đầu tiên của gray
        binary += gray[0];
        
        // Các bit tiếp theo: binary[i] = binary[i-1] XOR gray[i]
        for (int i = 1; i < gray.length(); i++) {
            if (binary[i-1] == gray[i]) {
                binary += "0";  // giống nhau thì XOR = 0
            } else {
                binary += "1";  // khác nhau thì XOR = 1
            }
        }
        
        cout << binary << endl;
    }
    
    return 0;
} 