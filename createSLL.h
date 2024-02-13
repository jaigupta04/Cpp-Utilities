#ifndef CREATESLL_H
#define CREATESLL_H

#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int info;
    Node* next;
};

// Function to create a new node
Node* createNode(int info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* createSLL(Node* start, int info) {
    Node* newNode = createNode(info);
    if (start == nullptr) {
        start = newNode;
    } else {
        Node* current = start;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    return start;
}

// Function to print the linked list
void printList(Node* start) {
    Node* current = start;
    while (current != nullptr) {
        cout << current->info << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to free the memory allocated for the linked list
void freeList(Node* start) {
    Node* current = start;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

#endif // CREATESLL_H
