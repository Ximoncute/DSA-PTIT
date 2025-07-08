#include <iostream>
#include <vector>
using namespace std;

int N, K;
int matrix[10][10];
vector<vector<int>> results;
bool used_col[10]; // Đánh dấu cột đã dùng
vector<int> current_solution; // Lưu cách chọn hiện tại

// Hàm đệ quy thử tất cả cách chọn
// row: hàng hiện tại đang xét
// current_sum: tổng hiện tại
void backtrack(int row, int current_sum) {
    // Trường hợp cơ sở: đã chọn hết N hàng
    if (row == N) {
        if (current_sum == K) {
            results.push_back(current_solution);
        }
        return;
    }
    
    // Thử tất cả các cột cho hàng hiện tại
    for (int col = 0; col < N; col++) {
        // Nếu cột này chưa được dùng
        if (!used_col[col]) {
            // Chọn phần tử [row][col]
            used_col[col] = true;
            current_solution.push_back(col + 1); // Lưu vị trí cột (1-indexed)
            
            // Đệ quy sang hàng tiếp theo
            backtrack(row + 1, current_sum + matrix[row][col]);
            
            // Backtrack
            current_solution.pop_back();
            used_col[col] = false;
        }
    }
}

int main() {
    cin >> N >> K;
    
    // Đọc ma trận
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Khởi tạo
    for (int i = 0; i < N; i++) {
        used_col[i] = false;
    }
    
    // Tìm tất cả cách chọn
    backtrack(0, 0);
    
    // In kết quả
    cout << results.size() << endl;
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j];
            if (j < results[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 