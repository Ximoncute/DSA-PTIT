#include <iostream>
using namespace std;

long long len[94];

void init() {
    len[1] = len[2] = 1;
    for(int i = 3; i < 94; i++) {
        len[i] = len[i-2] + len[i-1];
    }
}

char getChar(int n, long long k) {
    if(n == 1) return '0';
    if(n == 2) return '1';
    if(k <= len[n-2]) return getChar(n-2, k);
    else return getChar(n-1, k - len[n-2]);
}

int main() {
    int T; cin >> T;
    init();
    while(T--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << getChar(n, k) << endl;
    }
    return 0;
}