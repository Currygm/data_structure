#include <iostream>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;
    int height = -1;
};
void makeEmpty(node* T) {
    if (T == nullptr) return;
    else {
        makeEmpty(T -> left);
        makeEmpty(T -> right);
        delete T;
    }
}

node* find(int data, node* T) {
    if (T == nullptr) return nullptr;
    else if (data < T -> val) {
        return find(data, T -> left);
    }
    else if (data > T -> val) {
        return find(data, T -> right);
    }
    else return T;
}

node* findmin(node* T) {
    if (T == nullptr) return nullptr;
    else {
        if (T -> left != nullptr) {
            return findmin(T -> left);
        }
    }
    // 当前节点为叶节点
    return T;
}
node* singlerotate(node* k) {
    if (k -> left -> height > k -> right -> height) {
        node* k1 = k -> left;
        k -> left = k1 -> right;
        k1 -> right = k;
        k -> height = (k -> left -> height > k -> right -> height? k -> left -> height : k -> right -> height) + 1;
        k1 -> height = (k1 -> left -> height > k1 -> right -> height? k1 -> left -> height : k1 -> right -> height) + 1;
        return k1;
    }
    else {
        node* k1 = k -> right;
        k -> right = k1 -> left;
        k1 -> left = k;
        k -> height = (k -> left -> height > k -> right -> height? k -> left -> height : k -> right -> height) + 1;
        k1 -> height = (k1 -> left -> height > k1 -> right -> height? k1 -> left -> height : k1 -> right -> height) + 1;
        return k1;
    }
}
node* doublerotate(node* k) {
    if (k -> left -> height > k -> right -> height) {
        k -> left = singlerotate(k -> left);
        return singlerotate(k);
    }
    else {
        k -> right = singlerotate(k -> right);
        return singlerotate(k);
    }
}
// 构建平衡二叉树版本
node* insert(int data, node* T) {
    if (T == nullptr) {
        node* p = new node{data, nullptr, nullptr, 0};
        T = p;
    }
    else {
        if (data < T -> val) {
            T -> left = insert(data, T -> left);
            if (T -> left -> height - T -> right -> height == 2) {
                if (data < T -> left -> val) {
                    T = singlerotate(T);
                }
                else {
                    T = doublerotate(T);
                }
            }
        }
        else if (data > T -> val) {
            T -> right = insert(data, T -> right);
            if (T -> right -> height - T -> left -> height == 2) {
                if (data > T -> right -> val) {
                    T = singlerotate(T);
                }
                else {
                    T = doublerotate(T);
                }
            }
        }
    }
    T -> height = max(T -> left -> height, T -> right -> height) + 1;
    return T;
}

node* remove(int data, node* T) {
    // 不为当前节点的情况
    if (T == nullptr) return nullptr;
    else if (data < T -> val) {
        T -> left = remove(data, T -> left);
    }
    else if (data > T -> val) {
        T -> right = remove(data, T -> right);
    }
    // 删除节点为当前节点的情况
    // 有两个子节点，将右子树上的最小值挪到该节点，再删除右子树的最小值节点
    else if (T -> left && T -> right){
        node* pos = findmin(T -> right);
        T -> val = pos -> val;
        T -> right = remove(T -> val, T -> right);
    }
    // 有1或0个子节点
    else {
        node* tmp = T;
        if (T -> left) T = T -> left;
        else if (T -> right) T = T -> right;
        delete tmp;
    }
    return T;
}