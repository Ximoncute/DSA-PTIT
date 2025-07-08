#include <iostream>
using namespace std;

int n;
char s[20];

void Try(int i, int cnt6, int last8) {
    if (i == n) {
        if (s[0] == '8' && s[n-1] == '6')
            cout << s << endl;
        return;
    }
    // Thêm '6' nếu không quá 3 số 6 liên tiếp
    if (cnt6 < 3) {
        s[i] = '6';
        Try(i + 1, cnt6 + 1, 0);
    }
    // Thêm '8' nếu trước đó không phải là '8'
    if (last8 == 0) {
        s[i] = '8';
        Try(i + 1, 0, 1);
    }
}

int main() {
    cin >> n;
    Try(0, 0, 0);
    return 0;
}