#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int n, val;
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
    // Lọc phần tử trùng
    Node *p = First;
    while (p) {
        Node *q = p;
        while (q->next) {
            if (q->next->data == p->data) {
                Node *tmp = q->next;
                q->next = tmp->next;
                delete tmp;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
    // In danh sách sau khi lọc
    p = First;
    while (p) {
        cout << p->data;
        if (p->next) cout << " ";
        p = p->next;
    }
    return 0;
}