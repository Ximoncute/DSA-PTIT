#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // Đọc ma trận kề
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    // Chuyển đổi sang danh sách kề và in kết quả
    for(int i = 0; i < n; i++){
        vector<int> neighbors;
        
        // Tìm các đỉnh kề với đỉnh i+1 (vì đỉnh được đánh số từ 1)
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1){
                neighbors.push_back(j + 1); // j+1 vì đỉnh được đánh số từ 1
            }
        }
        
        // In danh sách kề của đỉnh i+1
        for(int k = 0; k < neighbors.size(); k++){
            cout << neighbors[k];
            if(k < neighbors.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 