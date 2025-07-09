#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char maxResult[10];

void backtrack(char s[], int k, int pos, int len) {
    // Cập nhật kết quả tốt nhất nếu tìm được số lớn hơn
    bool isGreater = false;
    for (int i = 0; i < len; i++) {
        if (s[i] > maxResult[i]) {
            isGreater = true;
            break;
        } else if (s[i] < maxResult[i]) {
            break;
        }
    }
    
    if (isGreater) {
        for (int i = 0; i < len; i++) {
            maxResult[i] = s[i];
        }
        maxResult[len] = '\0';
    }
    
    // Nếu hết lượt đổi hoặc đã xét hết vị trí
    if (k == 0 || pos >= len) {
        return;
    }
    
    // Tìm ký tự lớn nhất từ vị trí pos+1 trở đi
    char maxChar = s[pos];
    for (int i = pos + 1; i < len; i++) {
        if (s[i] > maxChar) {
            maxChar = s[i];
        }
    }
    
    // Nếu ký tự hiện tại đã là lớn nhất, chuyển sang vị trí tiếp theo
    if (s[pos] == maxChar) {
        backtrack(s, k, pos + 1, len);
    } else {
        // Thử đổi với tất cả vị trí có ký tự lớn nhất (từ phải sang trái)
        for (int i = len - 1; i > pos; i--) {
            if (s[i] == maxChar) {
                // Đổi chỗ
                char temp = s[pos];
                s[pos] = s[i];
                s[i] = temp;
                
                // Đệ quy với k-1 lần đổi
                backtrack(s, k - 1, pos + 1, len);
                
                // Backtrack
                temp = s[pos];
                s[pos] = s[i];
                s[i] = temp;
            }
        }
        
        // Cũng thử không đổi ở vị trí này
        backtrack(s, k, pos + 1, len);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int k;
        char s[10];
        cin >> k >> s;
        
        // Sao chép string ban đầu vào maxResult
        int len = 0;
        while (s[len] != '\0') len++; // Tính độ dài
        
        for (int i = 0; i < len; i++) {
            maxResult[i] = s[i];
        }
        maxResult[len] = '\0';
        
        backtrack(s, k, 0, len);
        
        cout << maxResult << endl;
    }
    
    return 0;
} 