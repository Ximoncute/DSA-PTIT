#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int BASE = 256;

int powP[MAXN];

void precompute_powP() {
    powP[0] = 1;
    for (int i = 1; i < MAXN; i++)
        powP[i] = (powP[i - 1] * BASE) % MOD;
}

class SegmentTree {
public:
    string s;
    vector<int> st;

    SegmentTree(string s) {
        int n = s.size();
        this->s = s;
        st.resize(4 * s.size());
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = s[l] - '0';  
            return;
        }
        int m = (l + r) >> 1;
        build(id * 2, l, m);              
        build(id * 2 + 1, m + 1, r);      
        int lenRight = r - m;
        st[id] = (st[id * 2] * powP[lenRight] + st[id * 2 + 1]) % MOD;
    }

    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = (l + r) >> 1;
        update(id * 2, l, m, pos, val);          
        update(id * 2 + 1, m + 1, r, pos, val);  
        int lenRight = r - m;
        st[id] = (st[id * 2] * powP[lenRight] + st[id * 2 + 1]) % MOD;
    }

    int get(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr)
            return (st[id] * powP[qr - r]) % MOD;
        int m = (l + r) >> 1;
        return (get(id * 2, l, m, ql, qr) + get(id * 2 + 1, m + 1, r, ql, qr)) % MOD;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute_powP(); 

    string s;
    cin >> s;
    int n = s.size();

    SegmentTree fw(s);
    reverse(s.begin(), s.end());
    SegmentTree bw(s);

    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'q') {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int hash1 = fw.get(1, 0, n - 1, l, r);
            int rl = n - r - 1;
            int rr = n - l - 1;
            int hash2 = bw.get(1, 0, n - 1, rl, rr);
            cout << (hash1 == hash2 ? "YES" : "NO") << '\n';
        } else {
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            int val = c - '0';
            fw.update(1, 0, n - 1, pos, val);
            int rpos = n - pos - 1;
            bw.update(1, 0, n - 1, rpos, val);
        }
    }
}