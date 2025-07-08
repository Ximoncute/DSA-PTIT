#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            
            if (type == 1) {
                // Trả về kích thước của queue
                cout << q.size() << endl;
            }
            else if (type == 2) {
                // Kiểm tra queue có rỗng không
                if (q.empty()) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
            else if (type == 3) {
                // Đẩy một số vào cuối queue
                int x;
                cin >> x;
                q.push(x);
            }
            else if (type == 4) {
                // Loại bỏ phần tử ở đầu queue
                if (!q.empty()) {
                    q.pop();
                }
            }
            else if (type == 5) {
                // Trả về phần tử ở đầu queue
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    cout << q.front() << endl;
                }
            }
            else if (type == 6) {
                // Trả về phần tử ở cuối queue
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    cout << q.back() << endl;
                }
            }
        }
    }
    
    return 0;
} 