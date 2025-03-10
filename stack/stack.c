#include "../node.c"
#include <stdio.h>
#include <stdlib.h>

struct stack {
	int size;
	struct Node* baseNode;
	struct Node* headNode;
};

struct stack* createStack() {
	struct stack* _stack = malloc(sizeof(struct stack));
	if(_stack == NULL) {
		printf("Error creating stack, heap full?\n");
		exit(1);
	}
	_stack->size = 0;
	_stack->baseNode = NULL;
	_stack->headNode = NULL;
	return _stack;
}

void appendStackItem(struct stack* stack, void* data) {
	// create stack item;
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (stack->baseNode == NULL) {
		stack->baseNode = newNode;
		stack->headNode = newNode;
	} else {
		struct Node* current = stack->baseNode;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
		stack->headNode = newNode;
	}

	stack->size++;
}

void* popStack(struct stack* stack) {
	// if stack is empty
	if (stack->headNode == NULL) {
		return NULL;
	}
	void* data = stack->headNode->data;
	if (stack->baseNode == stack->headNode) {
		free(stack->baseNode);
		stack->baseNode = NULL;
		stack->headNode = NULL;
	} else {
		struct Node* current = stack->baseNode;
		while(current->next != stack->headNode) {
			current = current->next;
		}
		current->next = NULL;
		free(stack->headNode);
		stack->headNode = current;
	}
	stack->size--;
	return data;
}
void printStack(struct stack* stack) {
	struct Node* current = stack->baseNode;

	while (current != NULL) {
		printf("%d -> ", *(int*)current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void freeStack(struct stack* stack) {
	struct Node* current = stack->baseNode;

	while (current != NULL) {
		struct Node* temp = current;
		current = current->next;
		free(temp);
	}
	
	free(stack);
}
