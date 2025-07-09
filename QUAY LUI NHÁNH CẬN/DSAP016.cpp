#include<iostream>
using namespace std;

int board[8][8];
int maxScore = 0;
bool cot[8], cheo1[15], cheo2[15];

void quayLui(int hang, int diemHienTai) {
    if (hang == 8) {
        if (diemHienTai > maxScore) {
            maxScore = diemHienTai;
        }
        return;
    }
    
    for (int c = 0; c < 8; c++) {
        if (!cot[c] && !cheo1[hang + c] && !cheo2[hang - c + 7]) {
            // Đặt quân hậu
            cot[c] = true;
            cheo1[hang + c] = true;
            cheo2[hang - c + 7] = true;
            
            // Đệ quy
            quayLui(hang + 1, diemHienTai + board[hang][c]);
            
            // Backtrack
            cot[c] = false;
            cheo1[hang + c] = false;
            cheo2[hang - c + 7] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int test = 1; test <= t; test++) {
        // Reset tất cả biến
        maxScore = 0;
        for (int i = 0; i < 8; i++) {
            cot[i] = false;
        }
        for (int i = 0; i < 15; i++) {
            cheo1[i] = false;
            cheo2[i] = false;
        }
        
        // Đọc dữ liệu bàn cờ
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> board[i][j];
            }
        }
        
        // Tìm kết quả tối ưu
        quayLui(0, 0);
        
        cout << "Test " << test << ": " << maxScore << endl;
    }
    
    return 0;
} 