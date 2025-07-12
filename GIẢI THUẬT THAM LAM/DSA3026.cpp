#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N, S;
    cin >> N >> S;
    
    // Kiểm tra các trường hợp không hợp lệ
    if(S == 0){
        if(N == 1){
            cout << "0 0" << endl;
        } else {
            cout << "-1 -1" << endl;
        }
        return 0;
    }
    
    // Nếu S > 9*N thì không thể tạo được số có N chữ số với tổng S
    if(S > 9 * N || S < 1){
        cout << "-1 -1" << endl;
        return 0;
    }
    
    // Tạo số nhỏ nhất
    string smallest(N, '0');
    int tempS = S;
    
    // Đặt chữ số đầu tiên là 1 để đảm bảo không bắt đầu bằng 0
    smallest[0] = '1';
    tempS -= 1;
    
    // Điền từ cuối về đầu để có số nhỏ nhất
    for(int i = N - 1; i >= 1 && tempS > 0; i--){
        int add = min(9, tempS);
        smallest[i] = char('0' + add);
        tempS -= add;
    }
    
    // Thêm phần còn lại vào chữ số đầu tiên
    smallest[0] = char('0' + 1 + tempS);
    
    // Tạo số lớn nhất
    string largest(N, '0');
    tempS = S;
    
    // Điền từ đầu về cuối để có số lớn nhất
    for(int i = 0; i < N && tempS > 0; i++){
        int add = min(9, tempS);
        largest[i] = char('0' + add);
        tempS -= add;
    }
    
    cout << smallest << " " << largest << endl;
    
    return 0;
}