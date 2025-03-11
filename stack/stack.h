#pragma once
#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	struct Node* baseNode;
	struct Node* headNode;
};

struct stack* createStack();
void appendStackItem(struct stack*, void* data);
void* popStack(struct stack* stack);
void printStack(struct stack* stack);
void freeStack(struct stack* stack);
