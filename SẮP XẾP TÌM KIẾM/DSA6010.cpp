#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Mảng đánh dấu chữ số đã xuất hiện (0-9)
        vector<bool> appeared(10, false);
        
        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            
            // Trường hợp đặc biệt khi số là 0
            if (num == 0) {
                appeared[0] = true;
                continue;
            }
            
            // Tách từng chữ số từ số num và đánh dấu
            while (num > 0) {
                appeared[num % 10] = true;
                num /= 10;
            }
        }
        
        // In ra các chữ số đã xuất hiện theo thứ tự tăng dần
        bool first = true;
        for (int i = 0; i < 10; i++) {
            if (appeared[i]) {
                if (!first) {
                    cout << " ";
                }
                cout << i;
                first = false;
            }
        }
        cout << endl;
    }
    
    return 0;
}
