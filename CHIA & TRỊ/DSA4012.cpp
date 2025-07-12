#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        
        int P[105], Q[105];
        
        // Đọc hệ số đa thức P
        for(int i = 0; i < m; i++){
            cin >> P[i];
        }
        
        // Đọc hệ số đa thức Q
        for(int i = 0; i < n; i++){
            cin >> Q[i];
        }
        
        // Khởi tạo mảng kết quả
        int R[205] = {0};
        
        // Nhân hai đa thức
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                R[i + j] += P[i] * Q[j];
            }
        }
        
        // In kết quả
        for(int i = 0; i < m + n - 1; i++){
            cout << R[i];
            if(i < m + n - 2) cout << " ";
        }
        cout << endl;
    }
    return 0;
} 