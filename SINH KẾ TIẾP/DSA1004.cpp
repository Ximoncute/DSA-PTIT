#include <iostream>
using namespace std;

int n, k, a[20];

void print() {
    for (int i = 1; i <= k; i++) cout << a[i];
    cout << " ";
}

void Try(int i, int start) {
    for (int j = start; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) print();
        else Try(i + 1, j + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        Try(1, 1);
        cout << endl;
    }
    return 0;
}