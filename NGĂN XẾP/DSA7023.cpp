#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string reverseWords(string s) {
    stack<string> wordStack;
    stringstream ss(s);
    string word;
    
    // Push each word onto the stack
    while (ss >> word) {
        wordStack.push(word);
    }
    
    // Pop words from stack to build reversed string
    string result = "";
    bool first = true;
    
    while (!wordStack.empty()) {
        if (!first) {
            result += " ";
        }
        result += wordStack.top();
        wordStack.pop();
        first = false;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after reading t
    
    while (t--) {
        string s;
        getline(cin, s);
        cout << reverseWords(s) << endl;
    }
    
    return 0;
} 