#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fenwick Tree (Binary Indexed Tree)
struct FenwickTree {
    vector<int> bit;
    int size;

    FenwickTree(int sz) : size(sz), bit(sz + 1, 0) {}

    void update(int idx, int delta) {
        for (++idx; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Query for sum in range [l, r]
    int query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> even_vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even_vals.push_back(a[i]);
        }
    }

    // Coordinate Compression
    sort(even_vals.begin(), even_vals.end());
    even_vals.erase(unique(even_vals.begin(), even_vals.end()), even_vals.end());

    auto get_compressed_idx = [&](int val) {
        return lower_bound(even_vals.begin(), even_vals.end(), val) - even_vals.begin();
    };

    int m = even_vals.size();
    FenwickTree ft_pre(m);
    FenwickTree ft_post(m);
    vector<int> post_evens_indices;

    long long total_inversions = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) { // Odd number is a separator
            // Move all numbers from post_odd to pre_odd
            for (int compressed_idx : post_evens_indices) {
                ft_post.update(compressed_idx, -1);
                ft_pre.update(compressed_idx, 1);
            }
            post_evens_indices.clear();
        } else { // Even number
            int compressed_idx = get_compressed_idx(a[i]);
            
            // This even number is A[j].
            // We need to count A[i]'s from ft_pre where A[i] > A[j].
            // This means querying for compressed indices > compressed_idx.
            total_inversions += ft_pre.query_range(compressed_idx + 1, m - 1);

            // Add current even number to the post_odd set
            ft_post.update(compressed_idx, 1);
            post_evens_indices.push_back(compressed_idx);
        }
    }

    cout << total_inversions << endl;

    return 0;
} 