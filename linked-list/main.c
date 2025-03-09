#include "./node.c"
#include <stdio.h>

int main() {
    // Create the head node with initial data.
    struct Node* head = createNode(10);

    // Insert additional nodes.
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    // Print the linked list.
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->nextNode;
    }
    printf("NULL\n");

    // Free the allocated memory.
    freeLinkedList(head);

    return 0;
}
