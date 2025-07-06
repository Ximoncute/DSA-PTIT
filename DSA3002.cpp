#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string amin = a, amax = a, bmin = b, bmax = b;
    for (char &c : amin) if (c == '6') c = '5';
    for (char &c : bmin) if (c == '6') c = '5';
    for (char &c : amax) if (c == '5') c = '6';
    for (char &c : bmax) if (c == '5') c = '6';
    int minsum = stoi(amin) + stoi(bmin);
    int maxsum = stoi(amax) + stoi(bmax);
    cout << minsum << " " << maxsum << endl;
    return 0;
}