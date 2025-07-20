#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

// Hàm tính giá trị tại ô (x, y)
long long getValue(long long x, long long y) {
    // Xác định layer (tầng) của ô (x, y)
    long long layer = max(x, y);
    
    // Số phần tử trong các layer từ 1 đến layer-1
    long long prev_elements = (layer - 1) * (layer - 1);
    
    // Xác định vị trí trong layer hiện tại
    long long pos_in_layer;
    
    if (x == layer) {
        // Ở cạnh phải của layer
        pos_in_layer = y;
    } else {
        // Ở cạnh dưới của layer
        pos_in_layer = 2 * layer - x;
    }
    
    return prev_elements + pos_in_layer;
}

// Hàm tìm vị trí của giá trị z
pair<long long, long long> getPosition(long long z) {
    // Tìm layer chứa giá trị z
    long long layer = 1;
    while (layer * layer < z) {
        layer++;
    }
    
    // Số phần tử trong các layer từ 1 đến layer-1
    long long prev_elements = (layer - 1) * (layer - 1);
    
    // Vị trí của z trong layer hiện tại
    long long pos_in_layer = z - prev_elements;
    
    long long x, y;
    
    if (pos_in_layer <= layer) {
        // Ở cạnh phải của layer
        x = layer;
        y = pos_in_layer;
    } else {
        // Ở cạnh dưới của layer
        x = 2 * layer - pos_in_layer;
        y = layer;
    }
    
    return make_pair(x, y);
}

int main() {
    long long x, y, z;
    cin >> x >> y;
    cin >> z;
    
    // Yêu cầu 1: Giá trị tại ô (x, y)
    cout << getValue(x, y) << endl;
    
    // Yêu cầu 2: Vị trí của giá trị z
    pair<long long, long long> pos = getPosition(z);
    cout << pos.first << " " << pos.second << endl;
    
    return 0;
} 