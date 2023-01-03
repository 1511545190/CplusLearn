//
// Created by 刘日亮 on 2022/12/31.
// 手写队列
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x);
};

Node::Node(int x) {
    data = x;
    next =NULL;
}

//链式队列，内存够用就不会满
class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue(){
        front=rear=NULL;
    }
    ~Queue(){
        Node* tmp = front;
        while(front){
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty(){
        return front == NULL;
    }
    void enQueue(int x){
        Node* temp = new Node(x);
        if(isEmpty()){
            front=rear = temp;
        }else{
            rear->next = temp;
            rear = temp;
        }

    }
    bool deQueue(int *x){
        if (isEmpty()) {
            return false;
        } else {
            *x = front->data;
            Node *p = front;
            front = front->next;

            delete p;
            if (front == NULL) rear = NULL;
            return true;
        }
    }

};

int main()
{
    Queue q;
    q.enQueue(0);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    int a;
    q.deQueue(&a);
    cout<<a<<endl;
    q.deQueue(&a);
    cout<<a<<endl;
    q.deQueue(&a);
    cout<<a<<endl;
    q.deQueue(&a);
    cout<<a<<endl;
    q.deQueue(&a);
    cout<<a<<endl;

    return 0;
}
