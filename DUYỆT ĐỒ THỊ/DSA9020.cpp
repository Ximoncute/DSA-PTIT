#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    
    // Khởi tạo ma trận kề với kích thước n x n, tất cả phần tử = 0
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    // Đọc danh sách kề cho từng đỉnh
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        
        if(!line.empty()){
            stringstream ss(line);
            int vertex;
            
            // Đọc các đỉnh kề với đỉnh i+1 (vì đỉnh được đánh số từ 1)
            while(ss >> vertex){
                matrix[i][vertex-1] = 1; // vertex-1 vì mảng đánh số từ 0
            }
        }
    }
    
    // In ma trận kề
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j];
            if(j < n-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 