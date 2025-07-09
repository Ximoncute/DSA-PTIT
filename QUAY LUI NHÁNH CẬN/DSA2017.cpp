#include <stdio.h>

int board[8][8];
int maxScore = 0;
int col[8]; // lưu cột của quân hậu ở hàng i

// hàm tính giá trị tuyệt đối
int myAbs(int x) {
    return x >= 0 ? x : -x;
}

// hàm tìm max
int myMax(int a, int b) {
    return a > b ? a : b;
}

// kiểm tra xem có thể đặt quân hậu ở (row, c) không
int canPlace(int row, int c) {
    for (int i = 0; i < row; i++) {
        // kiểm tra cùng cột
        if (col[i] == c) return 0;
        
        // kiểm tra đường chéo
        if (myAbs(i - row) == myAbs(col[i] - c)) return 0;
    }
    return 1;
}

// quay lui để đặt 8 quân hậu
void solve(int row, int currentScore) {
    if (row == 8) {
        maxScore = myMax(maxScore, currentScore);
        return;
    }
    
    // thử đặt quân hậu ở mỗi cột của hàng row
    for (int c = 0; c < 8; c++) {
        if (canPlace(row, c)) {
            col[row] = c;
            solve(row + 1, currentScore + board[row][c]);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        // đọc bàn cờ
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        
        maxScore = 0;
        solve(0, 0);
        
        printf("%d\n", maxScore);
    }
    
    return 0;
} 