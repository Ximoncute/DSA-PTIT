#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Mảng đếm bậc vào và bậc ra của từng đỉnh
        vector<int> inDegree(V + 1, 0);
        vector<int> outDegree(V + 1, 0);
        
        // Đọc các cạnh và tính bậc vào, bậc ra
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            outDegree[u]++;
            inDegree[v]++;
        }
        
        // Kiểm tra điều kiện chu trình Euler cho đồ thị có hướng
        bool hasEulerCycle = true;
        
        for(int i = 1; i <= V; i++) {
            // Với mỗi đỉnh, bậc vào phải bằng bậc ra
            if(inDegree[i] != outDegree[i]) {
                hasEulerCycle = false;
                break;
            }
        }
        
        if(hasEulerCycle) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
} 