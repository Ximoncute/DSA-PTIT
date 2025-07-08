#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> gray;
        
        // Trường hợp cơ sở: n = 1
        if (n == 1) {
            gray.push_back("0");
            gray.push_back("1");
        } else {
            // Bắt đầu với n = 1
            gray.push_back("0");
            gray.push_back("1");
            
            // Tăng dần từ 2 đến n
            for (int i = 2; i <= n; i++) {
                vector<string> new_gray;
                
                // Thêm '0' vào đầu các mã cũ (theo thứ tự bình thường)
                for (int j = 0; j < gray.size(); j++) {
                    new_gray.push_back("0" + gray[j]);
                }
                
                // Thêm '1' vào đầu các mã cũ (theo thứ tự ngược)
                for (int j = gray.size() - 1; j >= 0; j--) {
                    new_gray.push_back("1" + gray[j]);
                }
                
                gray = new_gray;
            }
        }
        
        // In kết quả
        for (int i = 0; i < gray.size(); i++) {
            cout << gray[i];
            if (i < gray.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 