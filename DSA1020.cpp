#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
        int i = n - 1;
        // Tìm bit 1 cuối cùng
        while (i >= 0 && s[i] == '0') {
            s[i] = '1';
            i--;
        }
        if (i >= 0) s[i] = '0';
        else {
            // Nếu là xâu đầu tiên, chuyển thành xâu cuối cùng (toàn 1)
            for (int j = 0; j < n; j++) s[j] = '1';
        }
        cout << s << endl;
    }
    return 0;
}