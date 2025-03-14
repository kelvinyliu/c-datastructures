#include "../node.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Node* createNodeItem(void* data, size_t dataSize) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Error creating node item.\n");
		return NULL;
	}
	newNode->data = malloc(dataSize);
	if (newNode->data == NULL) {
		printf("Error malloc data in node.\n");
		return NULL;
	}
	memcpy(newNode->data, data, dataSize);
	newNode->dataSize = dataSize;
	newNode->next = NULL;
	return newNode;
}

void appendStackItem(struct stack* stack, void* data, size_t dataSize) {
	struct Node* newNode = createNodeItem(data, dataSize);
	if (stack->baseNode == NULL || stack->size == 0) {
		stack->baseNode = newNode;
		stack->headNode = newNode;
	} else {
		stack->headNode->next = newNode;
		stack->headNode = newNode;
	}
	stack->size++;
}

void* popStack(struct stack* stack) {
	// if stack is empty
	if (stack->headNode == NULL || stack->size == 0) return NULL;

	// get data from head node
	void* data = malloc(stack->headNode->dataSize);
	if (data == NULL) {
		printf("Error popping head of stack.\n");
		return NULL;
	}
	memcpy(data, stack->headNode->data, stack->headNode->dataSize);
	
	// if stack has one element
	if (stack->baseNode == stack->headNode) {
		free(stack->headNode->data);
		free(stack->headNode);
		stack->headNode = NULL;
		stack->baseNode = NULL;
		stack->size--;
		return data;
	}

	// get the node before head
	struct Node* current = stack->baseNode;
	while(current->next != stack->headNode) {
		current = current->next;
	}
	free(stack->headNode->data);
	free(stack->headNode);
	current->next = NULL;
	stack->headNode = current;
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
		free(temp->data);
		free(temp);
	}
	
	free(stack);
}
