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

    // Thuật toán sắp xếp chèn (Insertion Sort)
    for (int i = 0; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử của arr[0...i-1], lớn hơn key,
        // về sau một vị trí
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Lưu lại trạng thái của mảng sau bước này
        std::stringstream ss;
        ss << "Buoc " << i << ": ";
        // In ra các phần tử từ 0 đến i
        for (int k = 0; k <= i; ++k) {
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
