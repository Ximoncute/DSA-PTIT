#include <stdio.h>
#include <string.h>

char strings[10][27];
int n;
int overlap[10][10]; // overlap[i][j] = số ký tự chung giữa strings[i] và strings[j]
int dp[1024][10];    // dp[mask][last] = min overlap khi đã dùng các string trong mask, kết thúc bằng string last

// Tính số ký tự chung giữa hai xâu
int countCommon(char* s1, char* s2) {
    int count = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }
    
    // Tính trước tất cả overlap
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                overlap[i][j] = countCommon(strings[i], strings[j]);
            }
        }
    }
    
    // Khởi tạo DP
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            dp[mask][last] = 999999;
        }
    }
    
    // Base case: chỉ có 1 string
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    
    // DP
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;
            if (dp[mask][last] == 999999) continue;
            
            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue; // next đã được sử dụng
                
                int newMask = mask | (1 << next);
                int newCost = dp[mask][last] + overlap[last][next];
                dp[newMask][next] = min(dp[newMask][next], newCost);
            }
        }
    }
    
    // Tìm kết quả
    int result = 999999;
    int fullMask = (1 << n) - 1;
    for (int last = 0; last < n; last++) {
        result = min(result, dp[fullMask][last]);
    }
    
    printf("%d\n", result);
    
    return 0;
} 