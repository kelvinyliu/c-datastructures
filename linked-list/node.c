#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node* nextNode;
};

struct Node* createNode(int data) {
	struct Node* newNode = malloc(sizeof(struct Node)); 
	if (newNode == NULL) {
		printf("Error trying to create node, heap potentially full?\n");
		exit(1);
	}
	newNode->data = data;
	newNode->nextNode = NULL;
    return newNode;
}

void insertNode(struct Node* parentNode, int data) {
	while (parentNode->nextNode != NULL) {
		parentNode = parentNode->nextNode;
	}
	struct Node* newNode = createNode(data);
	parentNode->nextNode = newNode;
}

bool searchLinkedList(struct Node* parentNode, int searchValue) {
	while (parentNode->nextNode != NULL) {
		if (parentNode->data == searchValue){
			return true;
		}
		parentNode = parentNode->nextNode;
	}
	return false;
}

void freeLinkedList(struct Node* parentNode) {
	struct Node* temp;

	while (parentNode != NULL) {
		temp = parentNode;
		parentNode = parentNode ->nextNode;
		free(temp);
	}
}
