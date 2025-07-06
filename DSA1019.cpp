#include <iostream>
using namespace std;

int n;
char s[17];

void Try(int pos, bool prevH) {
    if (pos > n) {
        if (s[1] == 'H' && s[n] == 'A') {
            for (int i = 1; i <= n; i++) cout << s[i];
            cout << endl;
        }
        return;
    }
    // Nếu là vị trí đầu tiên, phải là 'H'
    if (pos == 1) {
        s[pos] = 'H';
        Try(pos + 1, true);
    }
    // Nếu là vị trí cuối cùng, phải là 'A'
    else if (pos == n) {
        s[pos] = 'A';
        Try(pos + 1, false);
    }
    else {
        // Có thể đặt 'A' ở bất kỳ đâu
        s[pos] = 'A';
        Try(pos + 1, false);
        // Đặt 'H' nếu trước đó không phải 'H'
        if (!prevH) {
            s[pos] = 'H';
            Try(pos + 1, true);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        Try(1, false);
    }
    return 0;
}