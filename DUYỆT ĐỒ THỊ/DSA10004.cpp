#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Mảng đếm bậc của từng đỉnh
        vector<int> degree(V + 1, 0);
        
        // Đọc các cạnh và tính bậc của từng đỉnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }
        
        // Đếm số đỉnh có bậc lẻ
        int oddDegreeCount = 0;
        for(int i = 1; i <= V; i++) {
            if(degree[i] % 2 == 1) {
                oddDegreeCount++;
            }
        }
        
        // Kiểm tra điều kiện Euler
        if(oddDegreeCount == 0) {
            // Tất cả đỉnh có bậc chẵn → Chu trình Euler
            cout << "2" << endl;
        }
        else if(oddDegreeCount == 2) {
            // Có đúng 2 đỉnh bậc lẻ → Đường đi Euler
            cout << "1" << endl;
        }
        else {
            // Nhiều hơn 2 đỉnh bậc lẻ → Không có đường đi/chu trình Euler
            cout << "0" << endl;
        }
    }
    
    return 0;
} 