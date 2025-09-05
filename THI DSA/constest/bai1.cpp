#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        bool coSo[10] = {false}; 
        
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x == 0) {
                coSo[0] = true;
            } else {
                while (x > 0) {
                    int chuSo = x % 10;
                    if (chuSo % 2 == 0) { 
                        coSo[chuSo] = true;
                    }
                    x = x / 10;
                }
            }
        }
        bool coKetQua = false;
        for (int i = 0; i <= 8; i += 2) {
            if (coSo[i]) {
                if (coKetQua) cout << " ";
                cout << i;
                coKetQua = true;
            }
        }       
        if (!coKetQua) {
            cout << -1;
        }
        cout << endl;
    }    
    return 0;
} 