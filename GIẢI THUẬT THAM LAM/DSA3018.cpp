#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        // Số may mắn chỉ có chữ số 4 và 7
        // Để có số nhỏ nhất, ta cần ít chữ số nhất
        // Ưu tiên sử dụng chữ số 7 (lớn hơn) để giảm số lượng chữ số
        
        bool found = false;
        string result = "";
        
        // Thử từ số lượng chữ số 7 tối đa xuống 0
        int maxSevens = n / 7;
        
        for(int sevens = maxSevens; sevens >= 0; sevens--){
            int remaining = n - sevens * 7;
            
            // Kiểm tra xem phần còn lại có chia hết cho 4 không
            if(remaining % 4 == 0){
                int fours = remaining / 4;
                
                // Tạo số may mắn nhỏ nhất: đặt các chữ số 4 trước, sau đó là 7
                result = string(fours, '4') + string(sevens, '7');
                found = true;
                break;
            }
        }
        
        if(found){
            cout << result << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
} 