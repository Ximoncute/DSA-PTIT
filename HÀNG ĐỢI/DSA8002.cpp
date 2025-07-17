#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> Q;
    
    queue<int> q;
    
    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (operation == "POP") {
            if (!q.empty()) {
                q.pop();
            }
        }
        else if (operation == "PRINTFRONT") {
            if (q.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << q.front() << endl;
            }
        }
    }
    
    return 0;
} 