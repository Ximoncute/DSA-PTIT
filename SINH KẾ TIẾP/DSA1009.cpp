#include <iostream>
#include <string>
using namespace std;

int N, K;
int count_result = 0;

// Kiểm tra xâu có đúng một dãy K ký tự A liên tiếp không
bool check(string s) {
    int dem = 0; // số dãy A có độ dài >= K
    int lien_tiep = 0; // số A liên tiếp hiện tại
    
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') {
            lien_tiep++;
        } else {
            if (lien_tiep >= K) dem++;
            lien_tiep = 0;
        }
    }
    if (lien_tiep >= K) dem++;
    
    // Kiểm tra có đúng một dãy K A liên tiếp và không có dãy nào dài hơn K
    if (dem != 1) return false;
    
    // Kiểm tra không có dãy A nào dài hơn K
    lien_tiep = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A') {
            lien_tiep++;
            if (lien_tiep > K) return false;
        } else {
            lien_tiep = 0;
        }
    }
    
    return true;
}

// Sinh xâu và in kết quả
void sinh(string s, int pos) {
    if (pos == N) {
        if (check(s)) {
            cout << s << endl;
            count_result++;
        }
        return;
    }
    
    sinh(s + "A", pos + 1);
    sinh(s + "B", pos + 1);
}

// Lưu kết quả để in sau
string ket_qua[1000];
int so_luong = 0;

// Sinh xâu và lưu kết quả
void sinh_luu(string s, int pos) {
    if (pos == N) {
        if (check(s)) {
            ket_qua[so_luong] = s;
            so_luong++;
        }
        return;
    }
    
    sinh_luu(s + "A", pos + 1);
    sinh_luu(s + "B", pos + 1);
}

int main() {
    cin >> N >> K;
    
    sinh_luu("", 0);
    
    // In số lượng trước
    cout << so_luong << endl;
    
    // In các xâu
    for (int i = 0; i < so_luong; i++) {
        cout << ket_qua[i] << endl;
    }
    
    return 0;
} 