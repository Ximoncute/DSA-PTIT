#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isVowel(char x) {
    return x == 'A' || x == 'E';
}

bool check(string s) {
    int n = s.size();
    for (int i = 1; i < n - 1; i++) {
        if (isVowel(s[i]) && !isVowel(s[i - 1]) && !isVowel(s[i + 1]))
            return false;
    }
    return true;
}

int main() {
    char c;
    cin >> c;
    string s = "";
    for (char x = 'A'; x <= c; x++) s += x;
    sort(s.begin(), s.end());
    do {
        if (check(s)) cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}