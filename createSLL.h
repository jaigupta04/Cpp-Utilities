#ifndef CREATESLL_H
#define CREATESLL_H

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int info;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int info) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct node* createSLL(struct node* start, int info) {
    struct node* newNode = createNode(info);
    if (start == NULL) {
        start = newNode;
    } else {
        struct node* current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return start;
}

// Function to print the linked list
void printList(struct node* start) {
    struct node* current = start;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
    free(current);
}

// Function to free the memory allocated for the linked list
void freeList(struct node* start) {
    struct node* current = start;
    struct node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

#endif // CREATESLL_H
