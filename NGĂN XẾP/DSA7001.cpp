#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<int> stack;
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string command;
        ss >> command;
        
        if (command == "push") {
            int value;
            ss >> value;
            stack.push_back(value);
        }
        else if (command == "pop") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }
        else if (command == "show") {
            if (stack.empty()) {
                cout << "empty" << endl;
            } else {
                for (int i = 0; i < stack.size(); i++) {
                    if (i > 0) cout << " ";
                    cout << stack[i];
                }
                cout << endl;
            }
        }
    }
    
    return 0;
} 