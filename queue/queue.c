#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue* createQueue() {
	struct queue* _queue = malloc(sizeof(struct queue));
	if (_queue == NULL) {
		printf("Error creating the queue, heap full?\n");
		exit(1);
	}
	_queue->baseNode = NULL;
	_queue->tailNode = NULL;
	_queue->size = 0;
	return _queue;
}

void enQueue(struct queue* queue, void* data) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Error creating new node in queue.\n");
		exit(1);
	}
	
	newNode->data = data;
	newNode->next = NULL;
	if (queue->baseNode == NULL) {
		queue->baseNode = newNode;
		queue->tailNode = newNode;
	} else {
		queue->tailNode->next = newNode;
		queue->tailNode = newNode;
	}
	queue->size++;
}

// get item after head
// free current head
// set item after head as head
void* deQueue(struct queue* queue) {
	if (queue->baseNode == NULL || queue->size == 0) 
		return NULL;

	if (queue->size == 1) {
		void* data = queue->baseNode->data;
		free(queue->baseNode);
		queue->baseNode = NULL;
		queue->tailNode = NULL;
		queue->size--;
		return data;
	}

	struct Node* nextBase = queue->baseNode->next;
	void* data = queue->baseNode->data;
	free(queue->baseNode);
	queue->baseNode = nextBase;
	queue->size--;
	return data;
}

void queueFront(struct queue* queue) {
	if (queue->baseNode == NULL) {
		printf("NULL \n");
		return;
	}
	printf("%d\n",*(int*)queue->baseNode->data);
}

int queueSize(struct queue* queue) {
	return queue->size;
}

void freeQueue(struct queue* queue) {
	while(queue->baseNode != NULL) {
		deQueue(queue);
	}
	free(queue);
}

