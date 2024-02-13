#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;  

struct Node {
    int info;
    Node* next;
}*top = nullptr;

Node* createNode(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;
    return newNode;
}

void push(int item) {
    Node* newNode = createNode(item);
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Popped item -> " << top->info << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void displayStack() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack is:" << endl;
    Node* temp = top;

    while (temp != nullptr) {
        cout << "--> " << temp->info << endl;
        temp = temp->next;
    }
}

#endif // STACK_H
