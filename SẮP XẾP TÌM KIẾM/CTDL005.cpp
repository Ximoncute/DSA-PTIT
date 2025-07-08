#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n, x, val;
    cin >> n;
    Node *First = NULL, *Last = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        Node *node = new Node{val, NULL};
        if (!First) First = Last = node;
        else {
            Last->next = node;
            Last = node;
        }
    }
    cin >> x;
    // Xóa đầu
    while (First && First->data == x) {
        Node *tmp = First;
        First = First->next;
        delete tmp;
    }
    // Xóa giữa và cuối
    Node *p = First;
    while (p && p->next) {
        if (p->next->data == x) {
            Node *tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        } else {
            p = p->next;
        }
    }
    // In danh sách còn lại
    p = First;
    while (p) {
        cout << p->data;
        if (p->next) cout << " ";
        p = p->next;
    }
    return 0;
}