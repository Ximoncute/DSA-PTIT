#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    int l, r;
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Segment> seg(n);
        for (int i = 0; i < n; i++) cin >> seg[i].l >> seg[i].r;
        sort(seg.begin(), seg.end(), [](Segment a, Segment b) {
            return a.r < b.r;
        });
        int cnt = 1, last = seg[0].r;
        for (int i = 1; i < n; i++) {
            if (seg[i].l > last) {
                cnt++;
                last = seg[i].r;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}