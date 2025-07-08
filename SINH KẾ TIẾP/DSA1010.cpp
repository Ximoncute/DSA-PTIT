#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tìm tổ hợp tiếp theo theo thứ tự từ điển
bool next_combination(vector<int>& a, int N) {
    int K = a.size();
    
    // Tìm vị trí rightmost có thể tăng
    int i = K - 1;
    while (i >= 0 && a[i] == N - K + i + 1) {
        i--;
    }
    
    // Nếu không tìm thấy vị trí nào có thể tăng -> đã là tổ hợp cuối
    if (i < 0) {
        return false;
    }
    
    // Tăng a[i] và reset các phần tử phía sau
    a[i]++;
    for (int j = i + 1; j < K; j++) {
        a[j] = a[i] + (j - i);
    }
    
    return true;
}

// Đếm số phần tử khác nhau giữa hai tổ hợp
int count_different(vector<int>& old_group, vector<int>& new_group) {
    int count = 0;
    vector<bool> in_new(101, false); // đánh dấu ai có trong nhóm mới
    
    // Đánh dấu các thành viên trong nhóm mới
    for (int x : new_group) {
        in_new[x] = true;
    }
    
    // Đếm số người trong nhóm cũ không có trong nhóm mới
    for (int x : old_group) {
        if (!in_new[x]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> current(K);
        for (int i = 0; i < K; i++) {
            cin >> current[i];
        }
        
        vector<int> next_group = current;
        
        // Tìm tổ hợp tiếp theo
        if (!next_combination(next_group, N)) {
            // Nếu đã là tổ hợp cuối cùng, tất cả đều nghỉ
            cout << K << endl;
        } else {
            // Đếm số người được nghỉ
            int result = count_different(current, next_group);
            cout << result << endl;
        }
    }
    
    return 0;
} 