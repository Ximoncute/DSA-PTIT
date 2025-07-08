#include <iostream>
#include <string>
using namespace std;

bool check(int d, int m, int y) {
    if (m < 1 || m > 12) return false;
    int md[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) {
        if ((y%4==0 && y%100!=0) || (y%400==0)) return d <= 29 && d >= 1;
        else return d <= 28 && d >= 1;
    }
    return d >= 1 && d <= md[m];
}

int main() {
    for (int d1 : {0,2}) for (int d2 : {0,2})
    for (int m1 : {0,2}) for (int m2 : {0,2})
    for (int y1 : {2}) for (int y2 : {0,2}) for (int y3 : {0,2}) for (int y4 : {0,2}) {
        int d = d1*10 + d2;
        int m = m1*10 + m2;
        int y = y1*1000 + y2*100 + y3*10 + y4;
        if (y >= 2000 && check(d, m, y)) {
            printf("%02d/%02d/%d\n", d, m, y);
        }
    }
    return 0;
}