#include "../node.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node* createNode(void* data, size_t dataSize) {
	struct Node* newNode = malloc(sizeof(struct Node)); 
	if (newNode == NULL) {
		printf("Error trying to create node, heap potentially full?\n");
		exit(1);
	}

	newNode->data = malloc(dataSize);
	if (newNode->data == NULL){
		printf("Error allocation memory for data\n");
		exit(1);
	}

	memcpy(newNode->data, data, dataSize);
	newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* parentNode, int data) {
	while (parentNode->next != NULL) {
		parentNode = parentNode->next;
	}
	struct Node* newNode = createNode(&data, sizeof(data));
	parentNode->next = newNode;
}

bool searchLinkedList(struct Node* parentNode, int searchValue) {
	while (parentNode != NULL) {
		if (*(int*)parentNode->data == searchValue){
			return true;
		}
		parentNode = parentNode->next;
	}
	return false;
}

void freeLinkedList(struct Node* parentNode) {
	struct Node* temp;

	while (parentNode != NULL) {
		temp = parentNode;
		parentNode = parentNode->next;
		free(temp->data);
		free(temp);
	}
}
