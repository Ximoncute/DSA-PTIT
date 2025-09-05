#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long sum, maxPrefix, maxSuffix, maxSubarray;
    Node() : sum(0), maxPrefix(0), maxSuffix(0), maxSubarray(0) {}
};

int N, Q;
vector<long long> A;
vector<Node> segtree;

Node combine(const Node &left, const Node &right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.maxPrefix = max(left.maxPrefix, left.sum + right.maxPrefix);
    res.maxSuffix = max(right.maxSuffix, right.sum + left.maxSuffix);
    res.maxSubarray = max({left.maxSubarray, right.maxSubarray, left.maxSuffix + right.maxPrefix});
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        segtree[idx].sum = A[l];
        segtree[idx].maxPrefix = max(0LL, A[l]);
        segtree[idx].maxSuffix = max(0LL, A[l]);
        segtree[idx].maxSubarray = max(0LL, A[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    segtree[idx] = combine(segtree[idx*2], segtree[idx*2+1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return Node();
    if (ql <= l && r <= qr) return segtree[idx];
    int mid = (l + r) / 2;
    Node left = query(idx*2, l, mid, ql, qr);
    Node right = query(idx*2+1, mid+1, r, ql, qr);
    return combine(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    segtree.resize(4*(N+1));
    build(1, 1, N);

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        Node res = query(1, 1, N, L, R);
        cout << res.maxSubarray << "\n";
    }

    return 0;
}
