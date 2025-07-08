#include <stdio.h>
#include <string.h>

// Hàm đảo ngược chuỗi từ vị trí start đến end
void reverse(char s[], int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

// Tìm hoán vị kế tiếp theo thứ tự từ điển
int next_permutation(char s[]) {
    int n = strlen(s);
    
    // Bước 1: Tìm vị trí rightmost i sao cho s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    
    // Nếu không tìm thấy -> đã là hoán vị lớn nhất
    if (i < 0) {
        return 0; // false
    }
    
    // Bước 2: Tìm vị trí rightmost j sao cho s[j] > s[i]
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    
    // Bước 3: Hoán đổi s[i] và s[j]
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
    // Bước 4: Đảo ngược đoạn từ i+1 đến cuối
    reverse(s, i + 1, n - 1);
    
    return 1; // true
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int test_num;
        char s[85];
        
        scanf("%d %s", &test_num, s);
        
        if (next_permutation(s)) {
            printf("%d %s\n", test_num, s);
        } else {
            printf("%d BIGGEST\n", test_num);
        }
    }
    
    return 0;
} 