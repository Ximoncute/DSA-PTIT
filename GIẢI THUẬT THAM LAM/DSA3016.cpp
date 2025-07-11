#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int S, D;
        cin >> S >> D;
        
        // Kiểm tra tính hợp lệ
        if(S == 0){
            if(D == 1) cout << "0" << endl;
            else cout << "-1" << endl;
            continue;
        }
        
        if(S > 9 * D){
            cout << "-1" << endl;
            continue;
        }
        
        // Tạo mảng chứa các chữ số
        string result(D, '0');
        
        // Để có số nhỏ nhất, ta bắt đầu từ chữ số đầu tiên
        // Đặt chữ số đầu tiên là 1 để đảm bảo số không bắt đầu bằng 0
        result[0] = '1';
        int remaining = S - 1;
        
        // Điền từ cuối về đầu để có số nhỏ nhất
        for(int i = D - 1; i >= 1 && remaining > 0; i--){
            int add = min(9, remaining);
            result[i] = char('0' + add);
            remaining -= add;
        }
        
        // Thêm phần còn lại vào chữ số đầu tiên
        result[0] = char('0' + 1 + remaining);
        
        cout << result << endl;
    }
    return 0;
} 