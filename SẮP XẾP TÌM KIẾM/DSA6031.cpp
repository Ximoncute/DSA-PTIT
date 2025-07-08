#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // Loại bỏ phần tử không nằm trong cửa sổ hiện tại
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Loại bỏ phần tử nhỏ hơn a[i] từ cuối hàng đợi
            while (!dq.empty() && a[dq.back()] < a[i])
                dq.pop_back();

            dq.push_back(i); // Thêm chỉ số của a[i] vào deque

            // In phần tử lớn nhất của cửa sổ nếu đủ k phần tử
            if (i >= k - 1)
                cout << a[dq.front()] << " ";
        }
        cout << endl;
    }
    return 0;
}
