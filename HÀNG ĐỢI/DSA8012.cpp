#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> validNumbers;

void generateValidNumbers() {
    vector<int> digits = {0, 1, 2, 3, 4, 5};
    
    // Sinh số có 1 chữ số
    for (int i = 0; i <= 5; i++) {
        validNumbers.push_back(i);
    }
    
    // Sinh số có 2 chữ số
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            if (i != j) {
                validNumbers.push_back(i * 10 + j);
            }
        }
    }
    
    // Sinh số có 3 chữ số
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            if (i != j) {
                for (int k = 0; k <= 5; k++) {
                    if (k != i && k != j) {
                        validNumbers.push_back(i * 100 + j * 10 + k);
                    }
                }
            }
        }
    }
    
    // Sinh số có 4 chữ số
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            if (i != j) {
                for (int k = 0; k <= 5; k++) {
                    if (k != i && k != j) {
                        for (int l = 0; l <= 5; l++) {
                            if (l != i && l != j && l != k) {
                                validNumbers.push_back(i * 1000 + j * 100 + k * 10 + l);
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Sinh số có 5 chữ số
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            if (i != j) {
                for (int k = 0; k <= 5; k++) {
                    if (k != i && k != j) {
                        for (int l = 0; l <= 5; l++) {
                            if (l != i && l != j && l != k) {
                                for (int m = 0; m <= 5; m++) {
                                    if (m != i && m != j && m != k && m != l) {
                                        validNumbers.push_back(i * 10000 + j * 1000 + k * 100 + l * 10 + m);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Sinh số có 6 chữ số (chỉ có một số: 012345, 012354, ... nhưng không bắt đầu bằng 0)
    // Các số 6 chữ số sẽ > 100000 nên không cần thiết cho R <= 10^5
    
    sort(validNumbers.begin(), validNumbers.end());
}

int countValidNumbers(int L, int R) {
    int count = 0;
    for (int num : validNumbers) {
        if (num >= L && num <= R) {
            count++;
        }
        if (num > R) break; // Vì mảng đã được sắp xếp
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Sinh tất cả các số hợp lệ một lần
    generateValidNumbers();
    
    int T;
    cin >> T;
    
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    
    return 0;
} 