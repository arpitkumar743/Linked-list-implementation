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
    struct Node* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert a node at the beginning
void addAtStart(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

// Display the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete node from beginning
void deleteStart(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete node from end
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// MAIN function to test the linked list
int main() {
    struct Node* head = NULL;

    addAtEnd(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    printList(head); // 10 -> 20 -> 30 -> NULL

    addAtStart(&head, 5);
    printList(head); // 5 -> 10 -> 20 -> 30 -> NULL

    deleteStart(&head);
    printList(head); // 10 -> 20 -> 30 -> NULL

    deleteEnd(&head);
    printList(head); // 10 -> 20 -> NULL

    return 0;
}
