#include <iostream>
using namespace std;

void timSo(int n) {
    // Trường hợp đặc biệt
    if (n == 1) {
        cout << "9" << endl;
        return;
    }
    
    // Mảng lưu số dư và chuỗi tương ứng
    int parent[501];
    int digit[501];
    bool visited[501];
    int queue_mod[10000];
    int front = 0, back = 0;
    
    // Khởi tạo
    for (int i = 0; i <= 500; i++) {
        visited[i] = false;
        parent[i] = -1;
    }
    
    // Bắt đầu với số dư 9 % n
    int start_mod = 9 % n;
    visited[start_mod] = true;
    parent[start_mod] = -1;
    digit[start_mod] = 9;
    queue_mod[back++] = start_mod;
    
    while (front < back) {
        int current_mod = queue_mod[front++];
        
        // Nếu tìm thấy số chia hết cho n
        if (current_mod == 0) {
            // In ra kết quả bằng cách trace back
            char result[100];
            int len = 0;
            int temp = current_mod;
            
            while (parent[temp] != -1) {
                result[len++] = digit[temp] + '0';
                temp = parent[temp];
            }
            result[len++] = digit[temp] + '0';
            
            // In ngược lại
            for (int i = len - 1; i >= 0; i--) {
                cout << result[i];
            }
            cout << endl;
            return;
        }
        
        // Thử thêm '0'
        int next_mod0 = (current_mod * 10) % n;
        if (!visited[next_mod0]) {
            visited[next_mod0] = true;
            parent[next_mod0] = current_mod;
            digit[next_mod0] = 0;
            queue_mod[back++] = next_mod0;
        }
        
        // Thử thêm '9'
        int next_mod9 = (current_mod * 10 + 9) % n;
        if (!visited[next_mod9]) {
            visited[next_mod9] = true;
            parent[next_mod9] = current_mod;
            digit[next_mod9] = 9;
            queue_mod[back++] = next_mod9;
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        timSo(n);
    }
    
    return 0;
} 