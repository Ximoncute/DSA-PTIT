#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Cho std::swap
#include <sstream>   // Cho std::stringstream

// Hàm giải quyết một bộ test
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Dùng một vector các chuỗi để lưu lại các bước
    std::vector<std::string> steps;

    // Thuật toán sắp xếp chọn (Selection Sort)
    for (int i = 0; i < n - 1; ++i) {
        // Tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp [i, n-1]
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Đổi chỗ phần tử nhỏ nhất tìm được với phần tử đầu đoạn (arr[i])
        std::swap(arr[i], arr[min_idx]);

        // Lưu lại trạng thái của mảng sau bước này
        std::stringstream ss;
        ss << "Buoc " << (i + 1) << ": ";
        for (int k = 0; k < n; ++k) {
            ss << arr[k] << " ";
        }
        steps.push_back(ss.str());
    }

    // In các bước đã lưu theo thứ tự ngược lại
    for (int i = steps.size() - 1; i >= 0; --i) {
        std::cout << steps[i] << std::endl;
    }
}

int main() {
    // Theo ví dụ, chỉ có một bộ test. Nếu có nhiều bộ test, cần thêm vòng lặp.
    // int t; 
    // std::cin >> t; 
    // while (t--) {
    //     solve();
    // }
    solve(); // Gọi hàm giải quyết cho một bộ test
    return 0;
}
