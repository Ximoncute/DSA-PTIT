#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PhanTu {
    int giaTri;        
    int chiSoBanDau;   
    int khoangCach;    
};
bool soSanh(PhanTu a, PhanTu b) {
    if (a.khoangCach != b.khoangCach) {
        return a.khoangCach < b.khoangCach;
    }
    return a.chiSoBanDau < b.chiSoBanDau;
}
int main() {
    int T;
    cin >> T;   
    while (T--) {
        int n, X;
        cin >> n >> X;
        
        vector<PhanTu> mang;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            
            PhanTu pt;
            pt.giaTri = value;
            pt.chiSoBanDau = i;
            pt.khoangCach = abs(X - value);           
            mang.push_back(pt);
        }
        sort(mang.begin(), mang.end(), soSanh);
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << mang[i].giaTri;
        }
        cout << endl;
    }
    
    return 0;
} 