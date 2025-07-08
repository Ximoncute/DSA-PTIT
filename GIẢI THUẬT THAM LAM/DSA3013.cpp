#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

bool isPossible(int D, const string &S) {
    unordered_map<char, int> freq;
    for (char c : S) freq[c]++;

    // Max-heap: ký tự có tần suất lớn nhất ở đầu
    priority_queue<pair<int, char>> pq;
    for (auto &p : freq) {
        pq.push({p.second, p.first});
    }

    queue<pair<int, char>> waitQueue; // các ký tự đang chờ được xếp lại
    string result = "";

    while (!pq.empty()) {
        auto [count, ch] = pq.top(); pq.pop();
        result += ch;

        // Đưa vào hàng đợi chờ đợi để xử lý cooldown D vị trí
        waitQueue.push({count - 1, ch});

        if ((int)waitQueue.size() >= D) {
            auto [cnt, ch2] = waitQueue.front(); waitQueue.pop();
            if (cnt > 0) pq.push({cnt, ch2});
        }
    }

    return result.size() == S.size();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int D;
        string S;
        cin >> D >> S;
        if (isPossible(D, S)) cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}