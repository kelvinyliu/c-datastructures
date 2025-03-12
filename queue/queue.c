#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./queue.h"

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

void enQueue(struct queue* queue, void* data, size_t dataSize) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Error creating new node in queue.\n");
		exit(1);
	}
	
	if (data == NULL || dataSize == 0) {
		free(newNode);
		return;
	}

	newNode->data = malloc(dataSize);
	if (newNode->data == NULL) {
		printf("Error writing data into queue.\n");
		exit(1);
	}
	memcpy(newNode->data, data, dataSize);
	newNode->dataSize = dataSize;
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
	if (queue->baseNode == NULL || queue->size == 0) {
		return NULL;
	}
	void* data = malloc(queue->baseNode->dataSize);
	if (data == NULL) {
		printf("Error allocating memory in dequeue process.\n");
		exit(1);
	}
	memcpy(data, queue->baseNode->data, queue->baseNode->dataSize);
	struct Node* temp = queue->baseNode;
	queue->baseNode = queue->baseNode->next;
	free(temp->data);
	free(temp);
	if (queue->baseNode == NULL) {
 	   queue->tailNode = NULL;
	}
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
		void* data = deQueue(queue);
		free(data);
	}
	free(queue);
}

