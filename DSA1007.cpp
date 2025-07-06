#include <iostream>
using namespace std;

int n;
char s[11];

void Try(int i) {
    for (char c : {'A', 'B'}) {
        s[i] = c;
        if (i == n) {
            for (int j = 1; j <= n; j++) cout << s[j];
            cout << " ";
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        Try(1);
        cout << endl;
    }
    return 0;
}