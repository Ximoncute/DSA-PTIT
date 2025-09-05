#include <iostream>
#include <vector>
#include <string>
 #include <algorithm>
using namespace std;

void generate(int len, string s, vector<string>& res) {
    if (s.size() == len) {
        res.push_back(s);
        return;
    }
    generate(len, s + "6", res);
    generate(len, s + "8", res);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> res;
        for (int len = 1; len <= N; ++len) {
            generate(len, "", res);
        }
        cout << res.size() << endl;
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i + 1 < res.size()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

