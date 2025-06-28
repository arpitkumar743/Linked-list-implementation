#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int value;
    struct Node* next;
};

// Function to create a new node with given value
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory couldn't be allocated.\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the list
void addAtEnd(struct Node** head, int val) {
    struct Node* temp = *head;
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert a node at the start of the list
void addAtStart(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

//
