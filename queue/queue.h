#pragma once
#include "../node.c"

struct queue {
	struct Node* baseNode;
	struct Node* tailNode;
	int size;
};

// DSA methods
struct queue* createQueue();
void enQueue(struct queue* queue, void* data);
void* deQueue(struct queue* queue);
void queueFront(struct queue* queue);
int queueSize(struct queue* queue);
void freeQueue(struct queue* queue);
