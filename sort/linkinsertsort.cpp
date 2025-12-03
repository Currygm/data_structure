#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
};
int main () {
    int N, tmp;
    cin >> N;
    node* head = nullptr;
    node* cur = head;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        node* p = new node{tmp, nullptr};
        if (i == 0) {
            head = p;
            cur = head -> next;
        }
        else {
            cur = p;
            cur = cur -> next;
        }
    }
    cur = head -> next;
    while (cur) {
        node* nex = cur -> next;
        if (cur -> val < head -> val) {
            cur -> next = head;
            head = cur;
        }
        else {
            
        }
    }
}
