#include <iostream>
using namespace std;
template <typename T>  //同一个template下只能定义一个类
struct Node{           //可以写构造函数
    T data;
    Node* next;
};

template <typename T>
class Stack {
protected:
    Node<T>* head;     //调用模板类或模板函数都要用<T>声明类型.
    Node<T>* current;
    int size = 0;
public:
    Stack() {
        head = new Node<T>;
        current = head;
    }
    void push(const T& data) {
        Node<T>* new_node = new Node<T>{data, nullptr};
        current -> next = new_node;
        current = new_node;
    }
    void operator=(const Stack& origin) {
        Node<T>* head_node;
        if (origin == nullptr) {
            head_node = nullptr;
        }
        else {
            head_node = origin.head;
            Node<T>* curr = origin -> next;
            while (curr != nullptr) {
                Node<T>* new_node = new Node<T>{curr -> data, nullptr}
            }
        }
    }
};