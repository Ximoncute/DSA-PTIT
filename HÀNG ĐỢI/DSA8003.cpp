#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> Q;
    
    deque<int> dq;
    
    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "PUSHFRONT") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (operation == "PUSHBACK") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (operation == "POPFRONT") {
            if (!dq.empty()) {
                dq.pop_front();
            }
        }
        else if (operation == "POPBACK") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        }
        else if (operation == "PRINTFRONT") {
            if (dq.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << dq.front() << endl;
            }
        }
        else if (operation == "PRINTBACK") {
            if (dq.empty()) {
                cout << "NONE" << endl;
            } else {
                cout << dq.back() << endl;
            }
        }
    }
    
    return 0;
} 