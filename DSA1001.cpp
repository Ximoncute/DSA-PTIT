#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string X;
        cin >> X;
        int n = X.length();
        int i = n - 1;
        // Tìm bit '0' cuối cùng từ phải sang trái
        while (i >= 0 && X[i] == '1') {
            i--;
        }
        if (i < 0) {
            // Nếu toàn bộ là '1', xâu tiếp theo là toàn '0'
            for (int j = 0; j < n; ++j) cout << '0';
        } else {
            X[i] = '1';
            for (int j = i + 1; j < n; ++j) X[j] = '0';
            cout << X;
        }
        cout << endl;
    }
    return 0;
}