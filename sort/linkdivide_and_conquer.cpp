#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* combine (node* l, node* r) {
    node* dummy = new node{0, nullptr};
    node* cur = dummy;
    while (l || r) {
        if (l == nullptr || (r && l -> data > r -> data)) {
            cur -> next = r;
            r = r -> next;
        }
        else {
            cur -> next = l;
            l = l -> next;
        }
        cur = cur -> next;
    }
    return dummy -> next;
}
void mergesort (node* head, int len) {
    if (len <= 1) return;
    node* mid = head;
    for (int i = 0; i < len/2 - 1; i++) {    // 这里必须是len/2 - 1才能保证mid为中间值
        mid = mid -> next;
    }
    node* right = mid -> next;
    mid -> next = nullptr;
    mergesort(head, len/2);
    mergesort(right, len - len/2);           // 考虑int类型默认向下取整
    head = combine(head, right);
}
int main () {
    
}