#include <iostream>
using namespace std;

char arr[15];
int n, k;
char x[15];

void Try(int i, int pos) {
    for (int j = pos; j < n; j++) {
        x[i] = arr[j];
        if (i == k - 1) {
            for (int t = 0; t < k; t++) cout << x[t];
            cout << endl;
        } else {
            Try(i + 1, j);
        }
    }
}

int main() {
    char c;
    cin >> c >> k;
    n = c - 'A' + 1;
    for (int i = 0; i < n; i++) arr[i] = 'A' + i;
    Try(0, 0);
    return 0;
}