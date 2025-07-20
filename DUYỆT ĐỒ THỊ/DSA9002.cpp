#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Bỏ qua ký tự newline sau khi đọc n
    
    set<pair<int, int>> edges; // Sử dụng set để tự động sắp xếp và tránh trùng lặp
    
    // Đọc danh sách kề cho từng đỉnh
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        
        // Đọc tất cả các đỉnh kề của đỉnh i
        while (ss >> neighbor) {
            // Chỉ thêm cạnh nếu i < neighbor để tránh trùng lặp
            // (vì đồ thị vô hướng, cạnh (i,j) và (j,i) là như nhau)
            if (i < neighbor) {
                edges.insert({i, neighbor});
            }
        }
    }
    
    // In ra tất cả các cạnh theo thứ tự tăng dần
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    return 0;
} 