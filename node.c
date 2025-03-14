#pragma once
#include <stdlib.h>

struct Node {
	void* data;
	size_t dataSize;
	struct Node* next;
};
