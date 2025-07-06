#include <iostream>
#include <vector>
using namespace std;

void print_union(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    while (i < n && j < m) {
        if (a[i] < b[j]) cout << a[i++] << " ";
        else if (a[i] > b[j]) cout << b[j++] << " ";
        else {
            cout << a[i] << " ";
            ++i; ++j;
        }
    }
    while (i < n) cout << a[i++] << " ";
    while (j < m) cout << b[j++] << " ";
    cout << endl;
}

void print_intersection(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    while (i < n && j < m) {
        if (a[i] < b[j]) ++i;
        else if (a[i] > b[j]) ++j;
        else {
            cout << a[i] << " ";
            ++i; ++j;
        }
    }
    cout << endl;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        print_union(a, b);
        print_intersection(a, b);
    }
    return 0;
}