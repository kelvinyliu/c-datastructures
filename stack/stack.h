#pragma once
#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	struct Node* baseNode;
	struct Node* headNode;
};

struct stack* createStack();
struct Node* createNodeItem(void* data, size_t dataSize);
void appendStackItem(struct stack*, void* data, size_t dataSize);
void* popStack(struct stack* stack);
void printStack(struct stack* stack);
void freeStack(struct stack* stack);
