#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

// Chuyển đổi từ vector sang string để làm key
string vectorToString(const vector<int>& state) {
    string result = "";
    for (int i = 0; i < 6; i++) {
        result += to_string(state[i]);
    }
    return result;
}

// Quay hình vuông bên trái theo chiều kim đồng hồ
vector<int> rotateLeft(vector<int> state) {
    // Vị trí trong bảng 2x3:
    // 0 1 2
    // 3 4 5
    // Hình vuông bên trái: 0,1,3,4
    int temp = state[0];
    state[0] = state[3];
    state[3] = state[4];
    state[4] = state[1];
    state[1] = temp;
    return state;
}

// Quay hình vuông bên phải theo chiều kim đồng hồ
vector<int> rotateRight(vector<int> state) {
    // Vị trí trong bảng 2x3:
    // 0 1 2
    // 3 4 5
    // Hình vuông bên phải: 1,2,4,5
    int temp = state[1];
    state[1] = state[4];
    state[4] = state[5];
    state[5] = state[2];
    state[2] = temp;
    return state;
}

int minSteps(vector<int> start, vector<int> target) {
    if (start == target) return 0;
    
    queue<pair<vector<int>, int>> q; // {state, steps}
    set<string> visited;
    
    q.push({start, 0});
    visited.insert(vectorToString(start));
    
    while (!q.empty()) {
        vector<int> current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Thử quay hình vuông bên trái
        vector<int> leftRotated = rotateLeft(current);
        if (leftRotated == target) {
            return steps + 1;
        }
        string leftKey = vectorToString(leftRotated);
        if (visited.find(leftKey) == visited.end()) {
            visited.insert(leftKey);
            q.push({leftRotated, steps + 1});
        }
        
        // Thử quay hình vuông bên phải
        vector<int> rightRotated = rotateRight(current);
        if (rightRotated == target) {
            return steps + 1;
        }
        string rightKey = vectorToString(rightRotated);
        if (visited.find(rightKey) == visited.end()) {
            visited.insert(rightKey);
            q.push({rightRotated, steps + 1});
        }
    }
    
    return -1; // Không tìm thấy (không xảy ra)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        vector<int> start(6), target(6);
        
        for (int i = 0; i < 6; i++) {
            cin >> start[i];
        }
        
        for (int i = 0; i < 6; i++) {
            cin >> target[i];
        }
        
        cout << minSteps(start, target) << endl;
    }
    
    return 0;
} 