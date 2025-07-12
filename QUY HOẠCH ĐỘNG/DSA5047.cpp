#include <iostream>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

// Kiểm tra xem mask có hợp lệ không (không có 2 bit liền kề = 1)
bool isValidMask(int mask) {
    for (int i = 0; i < 3; i++) {
        if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) {
            return false;
        }
    }
    return true;
}

// Kiểm tra xem 2 mask có thể đặt cạnh nhau không
bool canPlace(int mask1, int mask2) {
    // Không có ô nào ở cùng hàng được chọn ở cả 2 cột
    return (mask1 & mask2) == 0;
}

// Tính điểm của một mask tại cột col
int getScore(int A[][10001], int col, int mask) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (mask & (1 << i)) {
            score += A[i][col];
        }
    }
    return score;
}

int maxScore(int A[][10001], int N) {
    // Tạo danh sách các mask hợp lệ
    int validMasks[8];
    int numValidMasks = 0;
    
    for (int mask = 0; mask < 16; mask++) {
        if (isValidMask(mask)) {
            validMasks[numValidMasks++] = mask;
        }
    }
    
    // dp[i][j] = điểm tối đa tại cột i với mask j
    int dp[10001][8];
    
    // Khởi tạo giá trị âm vô cùng
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < numValidMasks; j++) {
            dp[i][j] = -1000000;
        }
    }
    
    // Cột 0: khởi tạo với tất cả các mask hợp lệ
    for (int j = 0; j < numValidMasks; j++) {
        dp[0][j] = getScore(A, 0, validMasks[j]);
    }
    
    // DP cho các cột tiếp theo
    for (int col = 1; col < N; col++) {
        for (int j = 0; j < numValidMasks; j++) {
            int currentMask = validMasks[j];
            int currentScore = getScore(A, col, currentMask);
            
            for (int k = 0; k < numValidMasks; k++) {
                int prevMask = validMasks[k];
                
                if (canPlace(prevMask, currentMask)) {
                    dp[col][j] = max_of_two(dp[col][j], dp[col-1][k] + currentScore);
                }
            }
        }
    }
    
    // Tìm kết quả tối đa
    int result = -1000000;
    for (int j = 0; j < numValidMasks; j++) {
        result = max_of_two(result, dp[N-1][j]);
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int A[4][10001];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        
        int result = maxScore(A, N);
        cout << result << endl;
    }
    
    return 0;
} 