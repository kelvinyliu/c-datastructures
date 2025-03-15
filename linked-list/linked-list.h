#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "../node.c"

struct linkedList {
	struct Node* baseNode;
	int size;
};


struct linkedList* createLinkedList();
struct Node* createNode(void* data, size_t dataSize);
void insertNode(struct linkedList* _linkedList, int data);
struct Node* getLinkedListIndexNode(struct linkedList* _linkedList, int index);
void* getLinkedListIndexData(struct linkedList* _linkedList, int index);
void* removeLinkedListIndex(struct linkedList* _linkedList, int index);
bool searchLinkedList(struct linkedList* _linkedList, int searchValue);
void freeLinkedList(struct linkedList* _linkedList);
