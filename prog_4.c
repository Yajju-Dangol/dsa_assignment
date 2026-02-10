#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end (helper)
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node after a given node
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* new_node = createNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Function to delete a node in a Doubly Linked List
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }
    
    // If head node is to be deleted
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    
    // Change next only if node to be deleted is NOT the last node
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    
    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    
    free(del);
}

// Function to print the list
void printList(Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    // Initial list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    
    printf("Initial Doubly Linked List:\n");
    printList(head);
    
    // Insert after 20 (second node)
    printf("\nInserting 25 after 20...\n");
    if (head && head->next) { // Checking if 20 exists
        insertAfter(head->next, 25); 
    }
    printList(head);
    
    // Delete 20
    printf("\nDeleting 20...\n");
    if (head && head->next) {
        deleteNode(&head, head->next);
    }
    printList(head);
    
    // Delete head (10)
    printf("\nDeleting head (10)...\n");
    if (head) {
        deleteNode(&head, head);
    }
    printList(head);

    return 0;
}
