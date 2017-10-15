#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char* value;
	struct Node* next;
	struct Node* prev;
} Node;
typedef struct LinkedList {
	Node* head;
	Node* tail;
	int size;
} LinkedList;

LinkedList* init() {
	LinkedList* l = malloc(sizeof(LinkedList));
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
	return l;
}
int find(LinkedList* l, char* x) {
	Node* ptr = l->head;
	while (ptr) {
		if (strcmp(ptr->value, x) == 0)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

void addFront(LinkedList* l, char* x) {
	Node* newNode = malloc(sizeof(Node));
	newNode->value = malloc(sizeof(char)*(strlen(x)+1));
	strcpy(newNode->value,x);
	if (l->size == 0) {
		l->head = newNode;
		l->tail = newNode;
		newNode->next = NULL;
		newNode->prev = l->head;
	} else {
		Node* oldFront = l->head;
		newNode->next = oldFront;
		oldFront->prev = newNode;
		l->head = newNode;
	}
	l->size++;
}

void removeEnd(LinkedList* l) {
	if (l->size == 0)
		return;
	if (l->size == 1) {
		free(l->head);
		l->head = NULL;
		l->tail = NULL;
		l->size--;
	} else {
		Node* ptr = l->head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		l->tail = ptr->prev;
		free(ptr);
	}

}
void removeFront(LinkedList* l) {
	if (l->size == 0)
		return;
	if (l->size == 1) {
		free(l->head);
		l->head = NULL;
		l->tail = NULL;
		l->size--;
	} else {
		Node* ptr = l->head;
		l->head = ptr->next;
		free(ptr);
	}

}

void print(LinkedList* l) {
	Node* ptr = l->head;
	while (ptr != NULL) {
		printf("%s -", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}
int isEmpty(LinkedList* l) {
	if (l->head)
		return 1;
	else
		return 0;
}
