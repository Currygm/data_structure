#include <iostream>
#include <exception>
#include <string>
using namespace std;
static int max_length = 10;
class overqueue: public exception {
public:
    string message;
    overqueue(const string& s): message(s){}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class underqueue: public exception {
    string message;
    underqueue(const string& s): message(s){}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
template<typename T>
class queue {
public:
    int fron = 0, rear = 0, count = 0;
    T que[10];
    bool empty() {
        return (count == 0);
    }
    void push(T& a) {
        try {
            if (count == 10) {
                throw overqueue("This queue is full!");
            }
            else {
                que[rear] = a;
                if (rear == 9) rear = 0;
                else rear += 1;
                count += 1;
            }
        } catch (const overqueue& e) {
            cerr << e.what() << endl;
        }
    }
    T& front() {
        try {
            if (count == 0) {
                throw underqueue("This queue is empty!");
            }
            else {
                return que[front];
            }
        } catch (const underqueue& e) {
            cerr << e.what() << endl;
        }
    }
    T& back() {
        try {
            if (count == 0) {
                throw underqueue("This queue is empty!");
            }
            else {
                if (rear == 0) {
                    return que[9];
                }
                else {
                    return que[rear - 1];
                }
            }
        } catch (const underqueue& e) {
            cerr << e.what() << endl;
        }
    }
    int size() {
        return count;
    }
    void pop() {
        try {
            if (empty()) {
                throw underqueue("This queue is empty!");
            }
            else {
                if (rear == 0) {
                    rear = 9;
                }
                else {
                    rear -= 1;
                }
            }
        } catch (const underqueue& e) {
            cerr << e.what() << endl;
        }
    }
};