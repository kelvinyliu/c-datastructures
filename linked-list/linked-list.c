#include "../node.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct linkedList {
	struct Node* baseNode;
	int size;
};

struct linkedList* createLinkedList() {
	struct linkedList* _linkedList = malloc(sizeof(struct linkedList));
	if (_linkedList == NULL) {
		printf("Error creating linked list.\n");
		exit(1);
	}
	_linkedList->baseNode = NULL;
	_linkedList->size = 0;
	return _linkedList;
}

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

void insertNode(struct linkedList* _linkedList, int data) {
    struct Node* newNode = createNode(&data, sizeof(data));

    if (_linkedList->baseNode == NULL) {  
        _linkedList->baseNode = newNode;
    } else {
        struct Node* current = _linkedList->baseNode;
        while (current->next != NULL) {  
            current = current->next;
        }
        current->next = newNode;
    }

    _linkedList->size++;
}

bool searchLinkedList(struct linkedList* _linkedList, int searchValue) {
	struct Node* temp = _linkedList->baseNode;
	while (temp != NULL) {
		if (temp->data != NULL && *(int*)temp->data == searchValue){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void freeLinkedList(struct linkedList* _linkedList) {
	struct Node* temp;

	while (_linkedList->baseNode != NULL) {
		temp = _linkedList->baseNode;
		_linkedList->baseNode = _linkedList->baseNode->next;
		free(temp->data);
		free(temp);
	}
	free(_linkedList);
}
