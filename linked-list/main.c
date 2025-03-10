#include "./node.c"
#include <stdio.h>

int main() {
	printf("Running tests...\n");

    // Test 1: Creating a new node
    struct Node* head = createNode(10);
    if (head->data == 10 && head->nextNode == NULL) {
        printf("Test 1 Passed: createNode() works correctly.\n");
    } else {
        printf("Test 1 Failed: createNode() didn't set data or nextNode correctly.\n");
    }

    // Test 2: Inserting nodes
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    if (head->nextNode->data == 20 && 
        head->nextNode->nextNode->data == 30 && 
        head->nextNode->nextNode->nextNode->data == 40) {
        printf("Test 2 Passed: insertNode() correctly inserts new nodes.\n");
    } else {
        printf("Test 2 Failed: insertNode() didn't insert values correctly.\n");
    }

    // Test 3: Searching for existing values
    if (searchLinkedList(head, 30)) {
        printf("Test 3 Passed: searchLinkedList() found an existing value.\n");
    } else {
        printf("Test 3 Failed: searchLinkedList() did not find an existing value.\n");
    }

    // Test 4: Searching for a non-existent value
    if (!searchLinkedList(head, 50)) {
        printf("Test 4 Passed: searchLinkedList() correctly identified missing value.\n");
    } else {
        printf("Test 4 Failed: searchLinkedList() found a non-existent value.\n");
    }

    // Test 5: Freeing memory
    freeLinkedList(head);
    printf("Test 5 Passed: Memory successfully freed (Check with Valgrind for leaks if needed).\n");

    printf("All tests completed.\n");
	return 0;
}
