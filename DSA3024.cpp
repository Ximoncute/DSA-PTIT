#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, end;
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) cin >> jobs[i].start >> jobs[i].end;
        sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
            return a.end < b.end;
        });
        int cnt = 1, last = jobs[0].end;
        for (int i = 1; i < n; i++) {
            if (jobs[i].start >= last) {
                cnt++;
                last = jobs[i].end;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}